# replace source list
cat << EOF > ~/.vimrc
set nu
set tabstop=4
syntax on
EOF

mv /etc/apt/sources.list.d/ubuntu.sources /etc/apt/ubuntu.sources.backup
cat << EOF > /etc/apt/sources.list.d/ubuntu.sources
Types: deb
URIs: https://mirrors.tuna.tsinghua.edu.cn/ubuntu
Suites: noble noble-updates noble-backports
Components: main restricted universe multiverse
Signed-By: /usr/share/keyrings/ubuntu-archive-keyring.gpg

# 默认注释了源码镜像以提高 apt update 速度，如有需要可自行取消注释
# Types: deb-src
# URIs: https://mirrors.tuna.tsinghua.edu.cn/ubuntu
# Suites: noble noble-updates noble-backports
# Components: main restricted universe multiverse
# Signed-By: /usr/share/keyrings/ubuntu-archive-keyring.gpg

# 以下安全更新软件源包含了官方源与镜像站配置，如有需要可自行修改注释切换
Types: deb
URIs: http://security.ubuntu.com/ubuntu/
Suites: noble-security
Components: main restricted universe multiverse
Signed-By: /usr/share/keyrings/ubuntu-archive-keyring.gpg

# Types: deb-src
# URIs: http://security.ubuntu.com/ubuntu/
# Suites: noble-security
# Components: main restricted universe multiverse
# Signed-By: /usr/share/keyrings/ubuntu-archive-keyring.gpg

# 预发布软件源，不建议启用
# Types: deb
# URIs: https://mirrors.tuna.tsinghua.edu.cn/ubuntu
# Suites: noble-proposed
# Components: main restricted universe multiverse
# Signed-By: /usr/share/keyrings/ubuntu-archive-keyring.gpg

# # Types: deb-src
# # URIs: https://mirrors.tuna.tsinghua.edu.cn/ubuntu
# # Suites: noble-proposed
# # Components: main restricted universe multiverse
# # Signed-By: /usr/share/keyrings/ubuntu-archive-keyring.gpg
EOF

apt update

apt install -y gcc g++ gdb cmake make git


# install gcc14.2.0
cd ~
apt install -y build-essential libmpc-dev libmpfr-dev libgmp-dev flex
git clone https://mirrors.tuna.tsinghua.edu.cn/git/gcc.git
cd gcc && git checkout releases/gcc-14.2.0
mkdir build && cd build
../configure --enable-languages=c,c++ --disable-multilib
make -j$(nproc) && make install

# remove gcc installed by apt
apt remove gcc -y

# install zlib
cd ~
git clone https://github.com/madler/zlib.git
cd zlib && git checkout v1.3.1
./configure 
make -j$(nproc) && make install

# install openssl
cd ~
git clone https://github.com/openssl/openssl.git
cd openssl && git checkout openssl-3.4.1
./Configure 
make -j$(nproc) && make install

# install absl
cd ~
git clone https://github.com/abseil/abseil-cpp.git
cd abseil-cpp && git checkout 20250127.0
mkdir build && cd build
cmake .. -DCMAKE_CXX_STANDARD=20 -DABSL_FIND_GOOGLETEST=OFF -DABSL_BUILD_TESTING=OFF -DABSL_USE_GOOGLETEST_HEAD=OFF
make -j$(nproc) && make install

# install protobuf
cd ~
git clone https://github.com/protocolbuffers/protobuf.git
cd protobuf && git checkout v29.3
git submodule update --init --recursive
mkdir build && cd build
cmake .. -Dprotobuf_ABSL_PROVIDER=package -Dprotobuf_BUILD_TESTS=OFF
make -j$(nproc) && make install

# install grpc
cd ~
git clone https://github.com/grpc/grpc.git
cd grpc && git checkout v1.70.1
git submodule update --init --recursive
mkdir build && cd build
cmake .. -DgRPC_ZLIB_PROVIDER=package -DgRPC_PROTOBUF_PROVIDER=package -DgRPC_SSL_PROVIDER=package -DgRPC_ABSL_PROVIDER=package -DCMAKE_CXX_STANDARD=20 -DgRPC_BUILD_TESTS=OFF
make -j$(nproc) && make install

# install boost
cd ~
wget https://archives.boost.io/release/1.87.0/source/boost_1_87_0.tar.gz
tar -zxvf boost_1_87_0.tar.gz
cd boost_1_87_0


