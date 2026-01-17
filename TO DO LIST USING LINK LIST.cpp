#include <iostream>
#include <string>
using namespace std;
struct Node{
	int taskNum;
	string task;
	bool status;
	Node *link;
};
class Todolist{
	private:
		Node *start,*tem,*curn;
	public:
        int tN;
		Todolist(){
			start=NULL;
			 tN=0;
		}
	void insert(){
		tN++;
		tem=new Node;
		cout<<" \n\t TO DO LIST \t\n";
		cout<<"Please enter your task\t\n";
		cin.ignore();
        getline(cin, tem->task);
        cout<<endl;
		tem->taskNum=tN;
		tem->status=false;
		tem->link=NULL;
		if(start==NULL){
			start=tem;
		}
		else{
			curn=start;
			while(curn->link!=NULL){
				curn=curn->link;
			}
			curn->link=tem;
		}
		
	
	}//insert end
	void display(){
		curn=start;
		cout<<" TO DO LIST \t\n";
		while(curn!=NULL){
			if(curn->status){
				cout<<"[OK] "<<curn->taskNum<<". "<<curn->task<<endl;
			}
			else{
				cout<<"[  ] "<<curn->taskNum<<". "<<curn->task<<endl;
			}
			curn=curn->link;
		}
	}//display end;
	void updateStatus(){
		int uts;
		cout<<"\n\tPLEASE enter update task status number\n ";
		cin>>uts;
		curn=start;
		while(curn!=NULL){
			if(curn->taskNum==uts){
				curn->status=true;
				cout<<"update successfuly\n";
				return;
			}
			curn=curn->link;
		}
		
	}//uts end
	void deletet(){
		if(start==NULL){
			cout<<"emty there is no task yet\n";
			return;
		}
		else{
		
		int dtn;
		cout<<"\n\t ENTER delete task number\n";
		cin>>dtn;
		curn=start;
		tem=NULL;
		while(curn!=NULL){
			if(curn->taskNum==dtn){
				if(curn==start){
					start=start->link;
					delete curn;
					return;
				}
				else{
				tem->link=curn->link;
				delete curn;
				
				}
			
				
			}
				tem=curn;
				curn=curn->link;
		}
	}
	}	
	
		
};





int main(){
	Todolist todolist;
	int choice;
	do{
		cout<<"1.insert 2. display 3.update status 4.delete 5.end";
		cout<<"ENTER your choice";
		cin>>choice;
		switch(choice){
			case 1:
				todolist.insert();
				break;
			case 2:
				todolist.display();
				break;
			case 3:
				todolist.updateStatus();
				break;
			case 4:
				todolist.deletet();
				break;
			case 5:
				cout<<"end";
				break;
		}
	}while(choice!=5);
  
    return 0;
}

