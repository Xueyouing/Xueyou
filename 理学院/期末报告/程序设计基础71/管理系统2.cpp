#include <iostream>
#include <string>
#include <vector>
using namespace std;

// �ɼ���
class Score {
public:
    string subject; // ѧ������
    int score; // ����

public:
    // ���캯��
    Score(string subject = "", int score = 0) {
        this->subject = subject;
        this->score = score;
    }
};

// ѧ����
class Student {
public:
    int id; // ѧ��
    char name[20]; // ����
    char gender[10]; // �Ա�
    int age; // ����
    string className; // �༶
    vector<Score> scores; // �洢ÿ�ſεĳɼ�

public:
    // ���캯��
    Student() {}

    // ��ӳɼ�
    void addScore(Score s) {
        scores.push_back(s);
    }

    // ɾ���ɼ�
    void deleteScore(string subject) {
        for (vector<Score>::iterator it = scores.begin(); it != scores.end(); it++) {
            if (it->subject == subject) {
                scores.erase(it);
                return;
            }
        }
    }

    // �޸ĳɼ�
    void updateScore(string subject, int score) {
        for (vector<Score>::iterator it = scores.begin(); it != scores.end(); it++) {
            if (it->subject == subject) {
                it->score = score;
                return;
            }
        }
    }

    // ��ѯ�ɼ�
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
    cout << "ѧ��\t����\t�Ա�\t����\t�༶\t��Ŀ\t����\n";
    cout << "----------------------------------------------------\n";
    for (vector<Student>::iterator it = students.begin(); it != students.end(); it++) {
        cout << it->id << "\t" << it->name << "\t" << it->gender << "\t" << it->age << "\t" << it->className << "\n";
        
        for (vector<Score>::iterator it2 = it->scores.begin(); it2 != it->scores.end(); it2++) {
            cout << "\t\t\t\t\t" << it2->subject << "\t" << it2->score << "\n";
        }

        cout << "----------------------------------------------------\n";
    }
}
// ���ѧ��
void addStudent(vector<Student>& students) {
    Student student;

    cout << "����ѧ�ţ�";
    cin >> student.id;

    cout << "����������";
    cin >> student.name;

    cout << "�����Ա�";
    cin >> student.gender;

    cout << "�������䣺";
    cin >> student.age;

    cout << "����༶��";
    cin >> student.className;

    // ���ſγ���ӳɼ�
    while (true) {
        string subject;
        int score;

        // ����γ����ͳɼ�
        cout << "�����Ŀ��������\"0\"������ӣ���";
        cin >> subject;

        if (subject == "0") {
            break;
        }

        cout << "�����Ŀ������";
        cin >> score;

        // ��ӳɼ�
        Score s(subject, score);
        student.addScore(s);
    }

    students.push_back(student);
    cout << "ѧ����ӳɹ���" << endl;
}

// �޸�ѧ��
void updateStudent(vector<Student>& students) {
    int id;

    cout << "����Ҫ�޸ĵ�ѧ��ѧ�ţ�";
    cin >> id;

    for (vector<Student>::iterator it = students.begin(); it != students.end(); it++) {
        if (it->id == id) {
            cout << "�����µ�������";
            cin >> it->name;

            cout << "�����µ��Ա�";
            cin >> it->gender;

            cout << "�����µ����䣺";
            cin >> it->age;

            cout << "�����µİ༶��";
            cin >> it->className;

            // ���ſγ��޸ĳɼ�
            while (true) {
                string subject;
                int score;

                // ����γ����ͳɼ�
                cout << "����γ���������\"0\"�����޸ģ���";
                cin >> subject;

                if (subject == "0") {
                    break;
                }

                cout << "�����Ŀ������";
                cin >> score;

                // �޸ĳɼ�
                it->updateScore(subject, score);
            }

            cout << "ѧ����Ϣ�޸ĳɹ���" << endl;
            return;
        }
    }

    cout << "�Ҳ�����ѧ������������ѧ���Ƿ���ȷ��" << endl;
}

// ɾ��ѧ��
void deleteStudent(vector<Student>& students) {
    int id;

    cout << "����Ҫɾ����ѧ��ѧ�ţ�";
    cin >> id;

    for (vector<Student>::iterator it = students.begin(); it != students.end(); it++) {
        if (it->id == id) {
            students.erase(it);
            cout << "ѧ����Ϣɾ���ɹ���" << endl;
            return;
        }
    }

    cout << "�Ҳ�����ѧ������������ѧ���Ƿ���ȷ��" << endl;
}

// ��ѯѧ����Ϣ�ͳɼ�
void queryStudent(vector<Student>& students) {
    int choice;

    cout << "�����ĸ�������ѯѧ����Ϣ��\n";
    cout << "1. ѧ��\n";
    cout << "2. ����\n";
    cout << "3. �༶\n";
    cin >> choice;

    switch (choice) {
        case 1: {
            int id;
            cout << "����ѧ�ţ�";
            cin >> id;

            for (vector<Student>::iterator it = students.begin(); it != students.end(); it++) {
                if (it->id == id) {
                   cout << "ѧ��\t����\t�Ա�\t����\t�༶\t��Ŀ\t����\n";
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

            cout << "�Ҳ�����ѧ������������ѧ���Ƿ���ȷ��" << endl;
            break;
        }
        case 2: {
            string name;
            cout << "����������";
            cin >> name;

            for (vector<Student>::iterator it = students.begin(); it != students.end(); it++) {
                if (it->name == name) {
                    cout << "ѧ��\t����\t�Ա�\t����\t�༶\t��Ŀ\t����\n";
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

            cout << "�Ҳ�����ѧ�����������������Ƿ���ȷ��" << endl;
            break;
        }
        case 3: {
            string className;
            cout << "����༶��";
            cin >> className;

            for (vector<Student>::iterator it = students.begin(); it != students.end(); it++) {
                if (it->className == className) {
                    cout << "ѧ��\t����\t�Ա�\t����\t�༶\t��Ŀ\t����\n";
                    cout << "----------------------------------------------------\n";
                    cout << it->id << "\t" << it->name << "\t" << it->gender << "\t" << it->age << "\t" << it->className << "\n";
                    cout << "----------------------------------------------------\n";

                    for (vector<Score>::iterator it2 = it->scores.begin(); it2 != it->scores.end(); it2++) {
                        cout << "\t\t\t\t\t" << it2->subject << "\t" << it2->score << "\n";
                    }

                    cout << "----------------------------------------------------\n";
                }
            }

            cout << "�Ҳ����ð༶��ѧ������������༶�Ƿ���ȷ��" << endl;
            break;
        }
        default:
            cout << "��Ч��ѡ�����������롣" << endl;
    }
}

// ������
int main() {
    vector<Student> students;

    while (true) {
    	cout <<"ѧ���ɼ�����ϵͳ\n";
        cout << "��ѡ���ܣ�\n";
        cout << "1. ���ѧ��\n";
        cout << "2. �޸�ѧ��\n";
        cout << "3. ɾ��ѧ��\n";
        cout << "4. ��ѯѧ��\n";
        cout << "5. ��ʾ����ѧ��\n";
        cout << "0. �˳�����\n";

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
                cout << "�����Ѿ��˳���" << endl;
                return 0;
            default:
                cout << "��Ч��ѡ�����������롣" << endl;
                break;
        }
    }
    return 0;
}
    
