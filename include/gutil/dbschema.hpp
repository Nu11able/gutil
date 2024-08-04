/**
 * Author: Nu11able
 * Date: 2024-08-05
 * License: MIT License
 */

#include <string_view>
#include <string>

namespace DB{

enum OnDuplicateUpdateTag {
    no_action,
	override,
	plus,
};


template<typename T>
struct DBColumnValue;

template<typename T>
struct DBColumn {
	DBColumn(std::string_view n, OnDuplicateUpdateTag tag_ = OnDuplicateUpdateTag::override, bool is_index_ = false) : 
        name(n), tag(tag_), is_index(is_index_) {}
	const std::string_view name;
	const OnDuplicateUpdateTag tag = OnDuplicateUpdateTag::override;
    const bool is_index = false;
	using value_type = T;

    DBColumnValue<T> operator=(T val) const {
        return DBColumnValue<T>(*this, val);
    }
};

template<typename T>
struct DBColumnValue {
	DBColumnValue(const DBColumn<T>& col, T val = T{}) : name(col.name), tag(col.tag), is_index(col.is_index), value(val) {}
	const std::string_view name;
	const OnDuplicateUpdateTag tag = OnDuplicateUpdateTag::override;
    const bool is_index = false;
	T value;
	using value_type = T;
};

template<typename T> 
class BaseDBTable {
public:
	template<typename ...Col>
	static int SELECT(Col&&... cols) {
        std::string select_column;
        std::string index_column;
        (BuildSelectCommand(select_column, index_column, cols), ...);
        select_column.pop_back();
        select_column.pop_back();

		std::string command = std::string("SELECT ") + select_column + " FROM " + std::string(T::table_name) +
            " WHERE " + index_column;
        std::cout << command << std::endl;
        return 0;
	}

	template<typename ...Col>
	static void UPDATE(DBColumnValue<Col>&&... cols) {
        int count = sizeof...(Col);
        int cur_index = 0;
        std::string column_str;
        std::string value_str;
        std::string dup_str;
        (BuildUpdateCommand(column_str, value_str, dup_str, cur_index, count, std::forward<DBColumnValue<Col>&&>(cols)), ...);

		std::string command = std::string("INSERT INTO ") + std::string(T::table_name) +
            + " (" + column_str + ") VALUES(" + value_str + ") ON DUPLICATE KEY UPDATE " + dup_str;
        std::cout << command << std::endl;
	}
private:
    template<typename Col>
	static void BuildSelectCommand(std::string& select_command, std::string& index_column, Col&& col) {
        using col_type = typename std::remove_reference<Col>::type; // 移除引用
        using value_type = typename col_type::value_type;
        select_command += std::string(col.name) + ", ";
        if constexpr (std::is_same_v<col_type, DBColumnValue<value_type>>) {
            if (index_column.empty())
                index_column = std::string(col.name) + " = " + std::to_string(col.value);
            else
                index_column += " AND " + std::string(col.name) + " = " + std::to_string(col.value);
        }
    }

    template<typename Col>
	static void BuildUpdateCommand(std::string& column_str, std::string& value_str, std::string& dup_str, int& index, int size, DBColumnValue<Col>&& col) {
        column_str += std::string(col.name);
        if constexpr(std::is_same_v<Col, std::string>) {
            value_str += "'" + col.value + "'";
        } else {
            value_str += std::to_string(col.value);
        }

        if (col.tag == OnDuplicateUpdateTag::override) {
            if constexpr(std::is_same_v<Col, std::string>)
                dup_str += std::string(col.name) + " = '" + col.value + "'";
            else
                dup_str += std::string(col.name) + " = " + std::to_string(col.value);
        } else if (col.tag == OnDuplicateUpdateTag::plus) {
            if constexpr(std::is_same_v<Col, std::string>)
                dup_str += std::string(col.name) + " = " + std::string(col.name) + " + '" + col.value + "'";
            else
                dup_str += std::string(col.name) + " = " + std::string(col.name) + " + " + std::to_string(col.value);
        }
        if (index++ != size - 1) {
            column_str += ", ";
            value_str += ", ";
            if (!dup_str.empty())
                dup_str += ", ";
        }
    }
};


}