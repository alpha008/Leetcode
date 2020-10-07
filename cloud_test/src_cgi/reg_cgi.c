#include<fcgi_stdio.h>
#include<fcgi_config.h>
#include <sys/time.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "make_log.h"
#include "cfg.h"
#include "cJSON.h"
#include "deal_mysql.h"

#define REG_LOG_MODULE       "cgi"
#define REG_LOG_PROC         "reg"
int get_reg_info(char *reg_buf, char *user, char *nick_name, char *pwd, char *tel,char *email)
{
    int ret = 0;
    cJSON * root = cJSON_Parse(reg_buf);
    if(NULL == root)
    {
        LOG(REG_LOG_MODULE, REG_LOG_PROC, "cJSON_Parse err\n");
        ret = -1;
        goto ↓END;
    }
    cJSON * child1 = cJSON_GetObjectItem(root, "userName");
    if(NULL == child1)
    {
        LOG(REG_LOG_MODULE, REG_LOG_PROC, "cJSON_GetObjectItem err\n");
        ret = -1;
        goto ↓END;
    }
    strcpy(user, child1->valuestring); //拷贝内容
    //昵称
    cJSON *child2 = cJSON_GetObjectItem(root, "nickName");
    if(NULL == child2)
    {
        LOG(REG_LOG_MODULE, REG_LOG_PROC, "cJSON_GetObjectItem err\n");
        ret = -1;
        goto ↓END;
    }
    strcpy(nick_name, child2->valuestring); //拷贝内容
    //密码
    cJSON *child3 = cJSON_GetObjectItem(root, "firstPwd");
    if(NULL == child3)
    {
        LOG(REG_LOG_MODULE, REG_LOG_PROC, "cJSON_GetObjectItem err\n");
        ret = -1;
        goto ↓END;
    }
    strcpy(pwd, child3->valuestring); //拷贝内容

    //电话
    cJSON *child4 = cJSON_GetObjectItem(root, "phone");
    if(NULL == child4)
    {
        LOG(REG_LOG_MODULE, REG_LOG_PROC, "cJSON_GetObjectItem err\n");
        ret = -1;
        goto ↓END;
    }
    strcpy(tel, child4->valuestring); //拷贝内容

    //邮箱
    cJSON *child5 = cJSON_GetObjectItem(root, "email");
    if(NULL == child5)
    {
        LOG(REG_LOG_MODULE, REG_LOG_PROC, "cJSON_GetObjectItem err\n");
        ret = -1;
        goto ↓END;
    }
    strcpy(email, child5->valuestring); //拷贝内容
}
/*
注册用户，成功返回0，失败返回-1，已存在返回-2
*/
int user_register(char *reg_buf){
    int ret = 0;
    MYSQL * conn = NULL;
    char mysql_user[256] = {0};
    char mysql_pwd[256] = {0};
    char mysql_db[256] = {0};
    ret = get_mysql_info(mysql_user, mysql_pwd, mysql_db);
    if(ret !=0)
        goto ↓END;
    LOG(REG_LOG_PROC, REG_LOG_PROC,"mysql_user = %s, nysql_pwd = %s,mysql_db = %s\n",mysql_user,mysql_pwd,mysql_db);
    char *user_name[128];
    char nick_name[128];
    char pwd[128];
    char tel[128];
    char email[128];
    ret = get_reg_info(reg_buf,user_name,nick_name, pwd,tel,email);
    if(ret!=0)
         goto ↓END;
    LOG(REG_LOG_MODULE, REG_LOG_PROC, "user_name = %s, nick_name = %s, pwd = %s, tel = %s, email = %s\n", user_name, nick_name, pwd, tel, email);
    conn = mysq_conn(mysql_user, mysql_pwd, mysql_db);
    if(conn == NULL)
    {
        LOG(REG_LOG_MODULE, REG_LOG_PROC, "msql_conn err\n");
        ret = -1;
        goto END;
    }
    mysql_query(conn, "set namse utf8");
    char sql_cmd[SQL_MAX_LEN] = {0};
    sprintf(sql_cmd, "select * from user_info where user_name = '%s'", user_name);
    int ret2 = 0;
    ret2 = process_result_one(conn , sql_cmd,NULL);
    if(ret2 == 2) //如果存在
    {
        LOG(REG_LOG_MODULE, REG_LOG_PROC, "【%s】该用户已存在\n");
        ret = -2;
        goto END;
    }
    struct timeval tv;
    struct tm *ptm;
    char time_str[128];
    gettimeofday(&tv, NULL);
    ptm = localtime(&tv.tv_sec);//把从1970-1-1零点零分到当前时间系统所偏移的秒数时间转换为本地时间
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", ptm);
        //sql 语句, 插入注册信息
    sprintf(sql_cmd, "insert into user_info (user_name, nick_name, password, phone, email, create_time) values ('%s', '%s', '%s', '%s', '%s', '%s')", user_name, nick_name, pwd, tel, email, time_str);

    if(mysql_query(conn, sql_cmd) != 0)
    {
        LOG(REG_LOG_MODULE, REG_LOG_PROC, "%s 插入失败：%s\n", sql_cmd, mysql_error(conn));
        ret = -1;
        goto END;
    }
END:
    if(conn != NULL)
        mysql_close(conn);
}

int main()
{
    while (FCGI_Accept() >=0)
    {
        char* contentLength = getenv("CONTENT_LENGTH");
        int len =0;
        printf("Content-tyoe: text/html\r\n\r\n");
        if(contentLength == NULL){
            len = 0;
        }else{
            len = atoi(contentLength);
        }
        if(len <=0){ //没有登录用户信息
            printf("No data from standard input \n");
            LOG(REG_LOG_MODULE, REG_LOG_PROC,"len = 0,No data from standard input");
        }else{
            char buf[4*1024] = {0};
            int ret = 0;
            char *out = NULL;
            ret = fread(buf, 1, len , len , stdin);
            if(ret == 0){
                LOG(REG_LOG_MODULE, REG_LOG_PROC,"fread(buf, 1, len , len , stdin) ERR");
                continue;
            }
            LOG(REG_LOG_MODULE, REG_LOG_PROC, "buf = %s\n",buf);
            ret = user_register(buf);
            if(ret == 0){ // 返回给前端  成功
                out = return_status("002");  //util_cgi.h
            }else if(ret == -1){// 返回给前端  失败
                out = return_status("004"); // util_cgi.h
            }else if(ret == -2){ // 用户已经存在
                out = return_status("003"); //util_cgi.h
            }
            if(out != NULL){
                printf(out);
                free(out);
            }
        }
    return 0;
}


















