# elog

###create###
    struct elog *el = elog_create("test.log");
###set appender###
```
elog_set_appender(el, &g_elog_appender_rollfile, "a+");
struct elog_rollfile_conf conf;
conf.file_max_num = 10;
conf.file_max_size = 1024*1024*1024;
elog_appender_rollfile_config(el, &conf);
```
###append log###
    elog_append(el, msg, msg_size);
###free###
    elog_free(el);


###customize appender###
the appender interface define in elog_appender.h, refrence 
* elog_appender_file
* elog_appender_rollfile
