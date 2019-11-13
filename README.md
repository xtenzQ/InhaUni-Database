# 🗄️ Database course
Repository for database course labs and assignment

## 👨‍💻 Contributors
 [@xtenzQ](https://github.com/xtenzQ), [@SiedlerLorenz](https://github.com/SiedlerLorenz), [@Eddie-Tang](https://github.com/Eddie-Tang)

## ⚙️ Set up your MySQL

1. GCC Compiler
```
$ sudo apt-get install gcc
```
2. MYSQL Server
```
$ sudo apt-get install mysql-server
$ mysql_secure_installation
```
3. MYSQL Client Library
```
$ sudo apt-get install libmysqlclient-dev
```
4. MySQL Library configuration
```
$ mysql_config --libs
$ mysql_config --cflags
```

## 🌐 Download

To install this project simply clone it to your folder:
```
$ git clone https://github.com/xtenzQ/Uni-Database.git
```

## 🔧 Compile

To successfully compile use `mysql` flags:

```
$ gcc -o test mysql_example.c $(mysql_config --cflags) $(mysql_config --libs)
```
## Labs

1. [Basic SQL](/Lab%201/)
2. [Database Access from C](/Lab%202/)
