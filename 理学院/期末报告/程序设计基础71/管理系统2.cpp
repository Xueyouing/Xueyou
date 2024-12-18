#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 成绩类
class Score {
public:
    string subject; // 学科名称
    int score; // 分数

public:
    // 构造函数
    Score(string subject = "", int score = 0) {
        this->subject = subject;
        this->score = score;
    }
};

// 学生类
class Student {
public:
    int id; // 学号
    char name[20]; // 姓名
    char gender[10]; // 性别
    int age; // 年龄
    string className; // 班级
    vector<Score> scores; // 存储每门课的成绩

public:
    // 构造函数
    Student() {}

    // 添加成绩
    void addScore(Score s) {
        scores.push_back(s);
    }

    // 删除成绩
    void deleteScore(string subject) {
        for (vector<Score>::iterator it = scores.begin(); it != scores.end(); it++) {
            if (it->subject == subject) {
                scores.erase(it);
                return;
            }
        }
    }

    // 修改成绩
    void updateScore(string subject, int score) {
        for (vector<Score>::iterator it = scores.begin(); it != scores.end(); it++) {
            if (it->subject == subject) {
                it->score = score;
                return;
            }
        }
    }

    // 查询成绩
    Score queryScore(string subject) {
        for (vector<Score>::iterator it = scores.begin(); it != scores.end(); it++) {
            if (it->subject == subject) {
                return *it;
            }
        }

        return Score();
    }
};
void displayStudents(vector<Student>& students) {
    cout << "学号\t姓名\t性别\t年龄\t班级\t科目\t分数\n";
    cout << "----------------------------------------------------\n";
    for (vector<Student>::iterator it = students.begin(); it != students.end(); it++) {
        cout << it->id << "\t" << it->name << "\t" << it->gender << "\t" << it->age << "\t" << it->className << "\n";
        
        for (vector<Score>::iterator it2 = it->scores.begin(); it2 != it->scores.end(); it2++) {
            cout << "\t\t\t\t\t" << it2->subject << "\t" << it2->score << "\n";
        }

        cout << "----------------------------------------------------\n";
    }
}
// 添加学生
void addStudent(vector<Student>& students) {
    Student student;

    cout << "输入学号：";
    cin >> student.id;

    cout << "输入姓名：";
    cin >> student.name;

    cout << "输入性别：";
    cin >> student.gender;

    cout << "输入年龄：";
    cin >> student.age;

    cout << "输入班级：";
    cin >> student.className;

    // 逐门课程添加成绩
    while (true) {
        string subject;
        int score;

        // 输入课程名和成绩
        cout << "输入科目名（输入\"0\"结束添加）：";
        cin >> subject;

        if (subject == "0") {
            break;
        }

        cout << "输入科目分数：";
        cin >> score;

        // 添加成绩
        Score s(subject, score);
        student.addScore(s);
    }

    students.push_back(student);
    cout << "学生添加成功！" << endl;
}

// 修改学生
void updateStudent(vector<Student>& students) {
    int id;

    cout << "输入要修改的学生学号：";
    cin >> id;

    for (vector<Student>::iterator it = students.begin(); it != students.end(); it++) {
        if (it->id == id) {
            cout << "输入新的姓名：";
            cin >> it->name;

            cout << "输入新的性别：";
            cin >> it->gender;

            cout << "输入新的年龄：";
            cin >> it->age;

            cout << "输入新的班级：";
            cin >> it->className;

            // 逐门课程修改成绩
            while (true) {
                string subject;
                int score;

                // 输入课程名和成绩
                cout << "输入课程名（输入\"0\"结束修改）：";
                cin >> subject;

                if (subject == "0") {
                    break;
                }

                cout << "输入科目分数：";
                cin >> score;

                // 修改成绩
                it->updateScore(subject, score);
            }

            cout << "学生信息修改成功！" << endl;
            return;
        }
    }

    cout << "找不到该学生，请检查输入学号是否正确。" << endl;
}

// 删除学生
void deleteStudent(vector<Student>& students) {
    int id;

    cout << "输入要删除的学生学号：";
    cin >> id;

    for (vector<Student>::iterator it = students.begin(); it != students.end(); it++) {
        if (it->id == id) {
            students.erase(it);
            cout << "学生信息删除成功！" << endl;
            return;
        }
    }

    cout << "找不到该学生，请检查输入学号是否正确。" << endl;
}

// 查询学生信息和成绩
void queryStudent(vector<Student>& students) {
    int choice;

    cout << "按照哪个条件查询学生信息：\n";
    cout << "1. 学号\n";
    cout << "2. 姓名\n";
    cout << "3. 班级\n";
    cin >> choice;

    switch (choice) {
        case 1: {
            int id;
            cout << "输入学号：";
            cin >> id;

            for (vector<Student>::iterator it = students.begin(); it != students.end(); it++) {
                if (it->id == id) {
                   cout << "学号\t姓名\t性别\t年龄\t班级\t科目\t分数\n";
                    cout << "----------------------------------------------------\n";
                    cout << it->id << "\t" << it->name << "\t" << it->gender << "\t" << it->age << "\t" << it->className << "\n";
                    cout << "----------------------------------------------------\n";

                    for (vector<Score>::iterator it2 = it->scores.begin(); it2 != it->scores.end(); it2++) {
                        cout << "\t\t\t\t\t" << it2->subject << "\t" << it2->score << "\n";
                    }

                    cout << "----------------------------------------------------\n";
                    return;
                }
            }

            cout << "找不到该学生，请检查输入学号是否正确。" << endl;
            break;
        }
        case 2: {
            string name;
            cout << "输入姓名：";
            cin >> name;

            for (vector<Student>::iterator it = students.begin(); it != students.end(); it++) {
                if (it->name == name) {
                    cout << "学号\t姓名\t性别\t年龄\t班级\t科目\t分数\n";
                    cout << "----------------------------------------------------\n";
                    cout << it->id << "\t" << it->name << "\t" << it->gender << "\t" << it->age << "\t" << it->className << "\n";
                    cout << "----------------------------------------------------\n";

                    for (vector<Score>::iterator it2 = it->scores.begin(); it2 != it->scores.end(); it2++) {
                        cout << "\t\t\t\t\t" << it2->subject << "\t" << it2->score << "\n";
                    }

                    cout << "----------------------------------------------------\n";
                    return;
                }
            }

            cout << "找不到该学生，请检查输入姓名是否正确。" << endl;
            break;
        }
        case 3: {
            string className;
            cout << "输入班级：";
            cin >> className;

            for (vector<Student>::iterator it = students.begin(); it != students.end(); it++) {
                if (it->className == className) {
                    cout << "学号\t姓名\t性别\t年龄\t班级\t科目\t分数\n";
                    cout << "----------------------------------------------------\n";
                    cout << it->id << "\t" << it->name << "\t" << it->gender << "\t" << it->age << "\t" << it->className << "\n";
                    cout << "----------------------------------------------------\n";

                    for (vector<Score>::iterator it2 = it->scores.begin(); it2 != it->scores.end(); it2++) {
                        cout << "\t\t\t\t\t" << it2->subject << "\t" << it2->score << "\n";
                    }

                    cout << "----------------------------------------------------\n";
                }
            }

            cout << "找不到该班级的学生，请检查输入班级是否正确。" << endl;
            break;
        }
        default:
            cout << "无效的选择，请重新输入。" << endl;
    }
}

// 主程序
int main() {
    vector<Student> students;

    while (true) {
    	cout <<"学生成绩管理系统\n";
        cout << "请选择功能：\n";
        cout << "1. 添加学生\n";
        cout << "2. 修改学生\n";
        cout << "3. 删除学生\n";
        cout << "4. 查询学生\n";
        cout << "5. 显示所有学生\n";
        cout << "0. 退出程序\n";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                updateStudent(students);
                break;
            case 3:
                deleteStudent(students);
                break;
            case 4:
                queryStudent(students);
                break;
            case 5:
                displayStudents(students);
                break;
            case 0:
                cout << "程序已经退出。" << endl;
                return 0;
            default:
                cout << "无效的选择，请重新输入。" << endl;
                break;
        }
    }
    return 0;
}
    
