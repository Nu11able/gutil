#include <iostream>
#include "gutil/dbschema.hpp"

using namespace DB;

class TblNewbieTask : public BaseDBTable<TblNewbieTask> {
public:
	inline static constexpr std::string_view table_name{ "tbl_newbie_task" };
	inline static const DBColumn<int> userid{ "userid", OnDuplicateUpdateTag::no_action, true };
	inline static const DBColumn<int> task_id{ "task_id" };
	inline static const DBColumn<int> task_status{ "task_status" };
	inline static const DBColumn<int> task_process{ "task_process" };
	inline static const DBColumn<std::string> task_detail{ "task_detail" };
};



int main() {
    TblNewbieTask::SELECT(TblNewbieTask::userid = 10, TblNewbieTask::task_process = 20, TblNewbieTask::task_id, TblNewbieTask::task_status);
    TblNewbieTask::UPDATE(TblNewbieTask::userid = 10, TblNewbieTask::task_process = 20, TblNewbieTask::task_detail = "hello world");
    return 0;
}
/* output
SELECT userid, task_process, task_id, task_status FROM tbl_newbie_task WHERE userid = 10 AND task_process = 20
INSERT INTO tbl_newbie_task (userid, task_process, task_detail) VALUES(10, 20, 'hello world') ON DUPLICATE KEY UPDATE task_process = 20, task_detail = 'hello world'
 */