#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
using namespace std;
#define M 100
int a[M];
int n;
void insert_num(int a[],int &n,int x);
void create(int a[],int n);
void process(int a[],int n);
int Sequential_search(int a[],int n,int x);
int binary_search(int a[],int n,int x);
int find_and_del_all(int a[],int &n,int x);
void delete_pos(int a[],int &n,int pos);
void sort(int a[],int n);
int main()
{
    return 0;
}

void create(int a[],int n)
{
    for(int i = 0;i<n;i++){ a[i] = rand() % 10 + 1; }
    sort(a,n);
}

void process(int a[],int n)
{
    for(int i = 0;i<n;i++){ cout << a[i] << " "; }
    cout << endl;
}

void insert_num(int a[],int &n,int x)
{
    int pos;
    int i = 0;
    while(i<n && a[i] < x)
    {
        i++;
    }
    pos = i;
    if(pos < n)
    {
        n++;
        for(int j = n-1;j>pos;j--)
        {
            a[j] = a[j-1];
        }
        a[pos] = x;
    }
    else
    {
        n++;
        a[n-1] = x;
    }
}

int Sequential_search(int a[],int n,int x)
{
    int i = 0;
    while(i<n && a[i]!=x)
    {
        i++;
    }
    if(i<n) { return i; }
    else return -1;
}


int binary_search(int a[],int n,int x)
{
    sort(a,n);
    int left = 0;
    int right = n-1;
    while(left<=right)
    {
        int mid = (right+left)/2;
        if(a[mid] == x) { return mid; }
        else if(a[mid] < x) { left = mid + 1;}
        else { right = mid - 1; }
    }
    return -1;
}

void delete_pos(int a[],int &n,int pos)
{
    for(int i = pos;i<n;i++)
    {
        a[i] = a[i+1];
    }
    n--;
}

int find_and_del_all(int a[],int &n,int x)
{
    if(Sequential_search(a,n,x)==0) {return 0;}
    else
    {
        for(int i = 0;i<n;i++)
        {
            if(a[i] == x)
            {
                delete_pos(a,n,i);
                i--;
            }
        }
        return 1;
    }
}

void sort(int a[],int n)
{
    for(int i = 0;i<n;i++)
    {
        for(int j = i+1;j<n;j++)
        {
            if(a[i] > a[j]) swap(a[i],a[j]);
        }
    }
}
