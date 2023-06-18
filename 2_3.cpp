#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;
struct Sinh_Vien
{
   long int ID;
   string last_name;
   string name;
   int day,month,year;
   string gendre;
   int score;
};
#define M 100
Sinh_Vien sv[M];
int n;
void input(Sinh_Vien a[],int n)
{
   for(int i = 0;i<n;i++)
   {
       cout << "Student's first name : ";getline(cin,a[i].name);
       cout << "Student's last name : ";getline(cin,a[i].last_name);
       cout << "ID : ";cin >> a[i].ID;
       cout << "Day : ";cin >> a[i].day;
       cout << "Month : ";cin >> a[i].month;
       cout << "Year : ";cin >> a[i].year;
       int gend ; cout << " [1] . Male\t\t [2] . Female " << endl;
       cout << "Gendre : ";cin >> gend;
       if(gend==1) a[i].gendre = "Male";
       else if(gend==2) a[i].gendre = "Female";
       cout << "Score : ";cin >> a[i].score;
       cin.ignore();
   }
}
void output(Sinh_Vien a[],int n)
{
   cout << "\t\t\t STUDENT'S LIST" << endl;
   for(int i = 0;i<n;i++)
   {
       cout << "NUMBER " << i+1 << endl;
       cout << "Name : " << a[i].name << " " << a[i].last_name << endl;
       cout << "ID : " << a[i].ID << endl;
       cout << "DD - MM - YYYY : " << a[i].day << " - " << a[i].month << " - " << a[i].year << endl;
       cout << "Gendre : " << a[i].gendre << endl;
       cout << "Average score : " << a[i].score << endl;
       cout << endl;
   }
   cout << endl;
}
void write_dat_file(Sinh_Vien a[],int n,string file_name)
{
   ofstream fo(file_name,ios::app);
   if(fo.is_open())
   {
   for(int i = 0;i<n;i++)
   {
    fo << a[i].name << "#" << a[i].last_name << "#" << a[i].ID << '#' << a[i].day << "-" << a[i].month << "-" << a[i].year << "#" << a[i].gendre << "#" << a[i].score << endl;
   }
   fo.close();
   }
   else cout << "Unable to open the file" << endl;
}

void readfile(string filename,vector<long int> id)
{
    ifstream fi(filename);
    if(fi.is_open())
    {
        string line;
        while(getline(fi,line))
        {
            istringstream iss(line);
            string IDstr,last_name_str,name_str,date_str,gendre_str,score_str;
            std::getline(iss, name_str, '#');
            std::getline(iss, last_name_str, '#');
            std::getline(iss, IDstr, '#');
            std::getline(iss, date_str, '#');
            std::getline(iss, gendre_str, '#');
            std::getline(iss, score_str, '#');
            long int Id = stol(IDstr);
            id.push_back(Id);
        }
    }
    for(int i = 0;i<id.size();i++)
    {
        cout << id[i] << " ";
    }
    cout << endl;
}

void trans(Sinh_Vien a,vector <Sinh_Vien> a1,int i)
{
    a.day = a1[i].day;
    a.month = a1[i].month;
    a.year = a1[i].year;
    a.name = a1[i].name;
    a.last_name = a1[i].last_name;
    a.ID = a1[i].ID;
    a.gendre = a1[i].gendre;
    a.score = a1[i].score;
}

void arrange(vector<long int>id,Sinh_Vien a[])
{
    vector <Sinh_Vien> v;
    for(int i = 0;i<id.size();i++)
    {
        v.push_back(a[i]);
    }

    for(int i = 0;i<v.size();i++)
    {
        int min = i;
        for(int j = i+1;j<v.size();j++)
        {
            if(id[min] > id[j])
            {
                min = j;
            }
        }
        swap(v[i],v[min]);
    }

    for(int i = 0;i<id.size();i++)
    {
        trans(a[i],v,i);
    }
}


int main()
{
   system("cls");
   cout << "Input the number of the student : ";cin >> n;cin.ignore();
   input(sv,n);
   system("cls");
   output(sv,n);
   write_dat_file(sv,n,"Sinhvien.dat");
   vector <long int> id;
   readfile("Sinhvien.dat",id);
   arrange(id,sv);
   cout << "After sorting : " << endl;
   output(sv,n);
   return 0;
}



