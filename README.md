![image](https://github.com/summerwunder/LibraryManagement/assets/134956419/0686e4ea-29b0-4132-acf3-22000177bd3c)# LibraryManagement

# LibraryManagement

![LibraryManagement](https://github.com/summerwunder/LibraryManagement/blob/main/assets/LibraryManagement.png)

## 简介

LibraryManagement 是一个基于 Qt 和 MySQL 的图书管理系统，旨在帮助图书馆管理图书的借阅和归还。

## 功能特性

- 学生管理：包括学生信息的添加、编辑和删除。
- 图书管理：包括图书信息的添加、编辑和删除。
- 图书借阅：学生可以借阅图书，并记录借阅日期和归还日期。
- 图书归还：学生可以归还已借阅的图书。
- 查询功能：支持根据学生信息和图书信息进行查询。
- 日志记录：记录图书借阅和归还的日志。

## 系统要求

- Qt 6.0 或更高版本
- MySQL 数据库

## 安装步骤

1. 克隆或下载本仓库到本地计算机。
2. 使用 Qt Creator 打开项目文件 `LibraryManagement.pro`。
3. 在 Qt Creator 中构建项目，并确保项目成功编译。
4. 配置 MySQL 数据库连接信息：
   - 在 MySQL 数据库中创建一个名为 `LibraryManagement` 的数据库。
   - 导入项目目录下的 `init.sql` 文件到 `LibraryManagement` 数据库中，以创建所需的表和视图。
   - 打开项目中的 `protocol.h` 文件，并根据你的 MySQL 数据库配置，修改连接字符串信息。
5. 运行图书管理系统。

## 使用指南

1. 登录：使用管理员账户登录系统。
2. 学生管理：在学生管理界面中，你可以添加、编辑和删除学生信息。
3. 图书管理：在图书管理界面中，你可以添加、编辑和删除图书信息。
4. 图书借阅：在图书借阅界面中，学生可以借阅图书，并记录借阅日期和归还日期。
5. 图书归还：在图书归还界面中，学生可以归还已借阅的图书。
6. 查询功能：在查询界面中，你可以根据学生信息和图书信息进行查询。
7. 日志记录：系统会记录图书借阅和归还的日志，你可以在日志界面中查看日志信息。

## 贡献

欢迎对本项目进行贡献！如果你发现问题或有改进建议，请提出 issue 。

## 作者

- 电子邮件：2405499352@qq.com
- GitHub: https://github.com/summerwunder

如有任何疑问或需要进一步帮助，请随时联系作者。

