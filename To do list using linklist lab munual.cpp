#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
//                                          ASAD ALI
//                                         24010101-057
//                                     TO :  Respected Ma'am Azka Mir    
struct Node {
    int taskNum;
    string task;
    bool status;
    Node *link;
};

class Todolist {
private:
    Node *start, *tem, *curn;
public:
    int tN;

    Todolist() {
        start = NULL;
        tN = 0;
    }

    void insert() {
        tN++;
        tem = new Node;
        cout << "\n\n\n\t\t\t TO DO LIST \t\n";
        cout << "\t\tPlease enter your task\t\n";
        cin.ignore();
        getline(cin, tem->task);
        cout << endl;
        tem->taskNum = tN;
        tem->status = false;
        tem->link = NULL;
        if (start == NULL) {
            start = tem;
        } else {
            curn = start;
            while (curn->link != NULL) {
                curn = curn->link;
            }
            curn->link = tem;
        }
    }

    void display() {
        curn = start;
        cout << " \n\n\t\tTO DO LIST \t\n";
        while (curn != NULL) {
            if (curn->status) {
                cout << "[?] " << curn->taskNum << ". " << curn->task << endl;
            } else {
                cout << "[ ] " << curn->taskNum << ". " << curn->task << endl;
            }
            curn = curn->link;
        }
    }

    void updateStatus() {
        int uts;
        cout << "\n\n\n\n\t\t\tPLEASE enter update task status number\n ";
        cin >> uts;
        curn = start;
        while (curn != NULL) {
            if (curn->taskNum == uts) {
                curn->status = true;
                cout << "\n\n\tupdate successfuly\n";
                return;
            }
            curn = curn->link;
        }
    }

    void deletet() {
        if (start == NULL) {
            cout << "\n\n\t\tempty there is no task yet\n";
            return;
        } else {
            int dtn;
            cout << "\n\n\n\t\t\t ENTER delete task number\n";
            cin >> dtn;
            curn = start;
            tem = NULL;
            while (curn != NULL) {
                if (curn->taskNum == dtn) {
                    if (curn == start) {
                        start = start->link;
                        delete curn;
                        return;
                    } else {
                        tem->link = curn->link;
                        delete curn;
                        return;
                    }
                }
                tem = curn;
                curn = curn->link;
            }
        }
    }
};

int main() {
    Todolist todolist;
    int choice;
    do {
        cout << "\n\n\n\t\t1.insert 2.display 3.update status 4.delete 5.end\n\t";
        cout << "ENTER your choice\n\t";
        cin >> choice;
        switch (choice) {
            case 1:
            system("cls");
                todolist.insert();
                  todolist.display();
                break;
            case 2:
            system("cls");
                todolist.display();
                break;
            case 3:
            system("cls");
                  todolist.display();
                todolist.updateStatus();
                break;
            case 4:
           system("cls");
             todolist.display();
                todolist.deletet();
                break;
            case 5:
           system("cls");
           for(int i=0;i<4;i++){
           cout<<".";
           
           }
                cout << "END PROGRAM Successful";
                break;
        }
    } while (choice != 5);

    return 0;
}
