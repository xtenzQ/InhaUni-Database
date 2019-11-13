## Exercise 1 
Create a function to insert new item into a `student` table

```C
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
```

## Exercise 2
Create a function to delete data by `ID` in given table

```C
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
```
