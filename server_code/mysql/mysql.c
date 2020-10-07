#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<mysql/mysql.h>
#if 0
创建一个数据库
create  database alpha
删除数据库
drop database alpha
使用数据库
use alpha
创建表
create  table book{
    id int primary key auto_increment,
    title varchar(255)
    author varchar(255)
    price DECIMAL(8,2)
    data varchar(32)
}
删除表
drop table book;
插入数据
insert into book()
#endif
void print_err(MYSQL *conn, const char *title){
    fprintf(stderr,"%s:\n Error %u (%s) \n",title, mysql_errno(conn),mysql_error(conn));
}

MYSQL* mysql_conn(char* user_name, char *passwd, char *db_name){
    MYSQL *conn = NULL;
    conn = mysql_init(NULL);
    if(conn == NULL)
    {
        fprintf("stderr", "mysql 初始化失败 \n");
        return NULL;
    }
    if(mysql_real_connect(conn , NULL, user_name, passwd, db_name, 0 ,NULL, 0) == NULL){
        fprintf(stderr, "mysql_conn 失败：Error %u(%s)\n",nysql_errno(conn),mysql_error(conn));
        mysql_close(conn);
        return NULL;
    }
    return conn;
}
void process_result_set(MYSQL*conn ,MYSQL_RES *res_set){
    MYSQL_ROW row;
    uint i = 0;
    while((row = mysql_fetch_row(res_set))!=NULL){
        for(i = 0; i < mysql_num_fields(res_set); i++){
            if(i > 0){
                fputc('\t',stdout);
            }
            printf("%s",row[i] !=NULL ? row[i] : "NULL");
        }
        fputc('\n',stdout);
    }
    if(mysql_errno(conn)!=0){
        print_error(conn, "mysql_fetch_row() failed");
    }else{
        printf("%lu rows returned \n", (ulong)mysql_num_rows(res_set));
    }

}
int main()
{
    char buf[512] = {0};
    MYSQL *conn = mysql_conn("root","123456","heihei");
    if(conn == NULL)
        return -1;
    mysql_query(conn, "set names utf8");
    sprintf(buf, "insert into (title,author,price,data) values('%s','%s', '%lf','%s'),
    "c++ primer","alpha" ,95.00,"2020/10/07");
    if(mysql_query(conn,buf) !=0){
        print_error(conn,"mysql_query error");
    }
    else{
         printf("插入成功，受影响行数: %lu\n",(ulong)mysql_affected_rows(conn));   
    }
    sprintf(buf, "select *from %s","book");
    if(mysql_query(conn,buf) !=0){
        print_error(conn,"mysql_query error");
    }
    else{
         MYSQL_RES *res_set;
         res_set = mysql_store_result(conn);
         if(res_set == NULL){
             print_error(con, "mysql_store_result failed\n");
         }else{
             precess_result_set(conn,res_set);
             mysql_free_result(res_set);
         }
    }
    mysql_close(conn);

    return 0;
}
















