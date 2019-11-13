#include <mysql.h>
#include <stdio.h>
#include <string.h>

/**
 * Displays error
 *
 * @param  conn  database connection
 * @param  query applied query/
 */
void display_error(MYSQL *conn, char *query) {
        if (mysql_query(conn, query)) {
                fprintf(stderr, "%s\n", mysql_error(conn));
                exit(1);
        }
}

/**
 * Inserts new student with given parameters into table "student"
 *
 * @param  conn    database connection
 * @param  id      primary key column
 * @param  name    name column
 * @param  dept    dept_name column
 * @param  credits credits column 
 */
void insert_new_student(MYSQL *conn, char *id, char *name, char *dept, int credits) {
        char *temp_query = "INSERT INTO student VALUES ('%s', '%s', '%s', %d);";
        char *query = (char *) malloc(strlen(temp_query) + 20);
        sprintf(query, temp_query, id, name, dept, credits);
        display_error(conn, query);
        free(query);
}

/**
 * Delete student with given id from given table
 *
 * @param  conn       database connection
 * @param  table_name name of the table in database
 * @param  id         student id
 */
void delete_by_id(MYSQL *conn, char *table_name, char *id) {
        char *temp_query = "DELETE FROM %s WHERE ID=%s;";
        char *query = (char *) malloc(strlen(temp_query) + 20);
        sprintf(query, temp_query, table_name, id);
        display_error(conn, query);
        free(query);
}

/**
 * Displays student with given name
 *
 * @param  conn database connection
 * @param  name student name
 * @param  id   student id
 */
void display_results(MYSQL *conn, char *name) {
        MYSQL_RES *res;
        MYSQL_ROW row;
        char *temp_query = "SELECT * FROM student WHERE name='%s';";
        char *query = (char *) malloc(strlen(temp_query) + 20);
        sprintf(query, temp_query, name);
        display_error(conn, query);
        res = mysql_use_result(conn);
        free(query);

        // Output table name
        printf("\n\n * * * * Result of query * * * * \n\n");
        puts("_______________________________________________________");
        puts("");
        printf("%10s | %30s | %20s | %10s\n\n", "ID", "Title", "Dept. Name", "Credits");
        while ((row = mysql_fetch_row(res)) != NULL)
                printf("%10s | %30s | %20s | %10s\n", row[0], row[1], row[2], row[3]);
        puts("_______________________________________________________");

        // Close connection
        mysql_free_result(res);
}

int main() {
        MYSQL *conn;

        char *server = "localhost";
        char *user = "group4";
        char *password = "12345678";
        char *database = "group4_university_db";

        conn = mysql_init(NULL);

        // Connect to the database
        if(!mysql_real_connect(conn, server, user, password, database, 0, NULL,0)){
                fprintf(stderr, "%s\n", mysql_error(conn));
                exit(1);
        }

        insert_new_student(conn, "1003", "Nikita", "Comp. Sci.", 3);
        delete_by_id(conn, "student", "1003");
        display_results(conn, "Nikita");

        mysql_close(conn);
}
