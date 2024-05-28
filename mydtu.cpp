#include<iostream>
using namespace std;
class person{
    string name;
	long long int mssv;
    string dmy;
    public:
    	person(){
		}
        person(string n,int m,string d){
            name=n;mssv=m;dmy=d;
        }
        void nhap(){
            cout<<"Input your name: ";
            getline(cin,name);
            cout<<"Input MSSV: ";cin>>mssv;
            cin.ignore();
            cout<<"Input your birthday: ";
            getline(cin,dmy);
        }
};
class scoresubject{
	private:
		string subject;
		float diem;
		int tc;
        string gpa;
	public:
		scoresubject(){
		}
		void nhap(){
	        cout<<"Input name of subject: ";getline(cin,subject);
	        cout<<"Input score: ";cin>>diem;
	        cout<<"Input credits of this subject: ";cin>>tc;
	        cout<<"--------------------------------"<<endl;
	        cin.ignore();
    	}
    	string getsubject(){
    		return subject;
		}
		float getdiem(){
			return diem;
		}
		int gettc(){
			return tc;
		}
        void setgpa(string g){
            gpa=g;
        }
        string getgpa(){
            return gpa;
        }
};
int tongtc=0;
class dtu:public person, public scoresubject{
	scoresubject *s;
	int sl;
    public:	
    	dtu(){
		}
        void nhap(){
        	person::nhap();
        	cout<<"Input number of subject: ";cin>>sl;
        	cin.ignore();cout<<endl;
        	s=new scoresubject[sl];
        	for(int i=0;i<sl;i++){
        		s[i].nhap();
			}
        }
        float GPA10(){
        	float tongdiem=0;
        	for(int i=0;i<sl;i++){
        		
        		tongdiem+=s[i].getdiem()*s[i].gettc();tongtc+=s[i].gettc();
			}
			cout<<endl<<"=> GPA [10]: ";
			return tongdiem/tongtc;
		}
        float GPA4(){
            float tong=0;
            for(int i=0;i<sl;i++){
                float diem = s[i].getdiem();
                int tc = s[i].gettc();
                if(diem>=9.5 && diem<=10){
                    tong += 4 * tc;s[i].setgpa("A+");
                }
                else if (diem>=8.5 && diem<=9.4) {
                    tong += 4 * tc;s[i].setgpa("A");
                } 
                else if (diem >= 8 && diem <= 8.4) {
                    tong += 3.65 * tc;s[i].setgpa("A-");
                } 
                else if (diem >= 7.5 && diem <= 7.9) {
                    tong += 3.33 * tc;s[i].setgpa("B+");
                } 
                else if (diem >= 7 && diem <= 7.4) {
                    tong += 3 * tc;s[i].setgpa("B");
                } 
                else if (diem >= 6.5 && diem <= 6.9) {
                    tong += 2.65 * tc;s[i].setgpa("B-");
                } 
                else if (diem >= 6 && diem <= 6.4) {
                    tong += 2.33 * tc;s[i].setgpa("C+");
                } 
                else if (diem >= 5.5 && diem <= 5.9) {
                    tong += 2 * tc;s[i].setgpa("C");
                } 
                else if (diem >= 4.5 && diem <= 5.4) {
                    tong += 1.65 * tc;s[i].setgpa("C-");
                } 
                else if (diem>=4 && diem<=4.4) {
                    tong += 1 * tc;s[i].setgpa("D");
                }
                // else s[i].setgpa("F");
            }
            
            return tong/tongtc;
        }
        void in(){
            for(int i=0;i<sl;i++){
                cout<<s[i].getsubject()<<": "<<s[i].getgpa()<<" | ";
            }
        }
        ~dtu(){
            delete[] s;
        }
};
int main(){
    dtu s1;
    s1.nhap();s1.GPA4();
    s1.in();
    cout<<s1.GPA10()<<endl;
    cout<<"=> GPA [4]: "<<s1.GPA4();
}