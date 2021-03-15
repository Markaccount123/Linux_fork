#include<iostream>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
using namespace std;

int main()
{
  pid_t id = fork();
  if(id < 0){
    cerr<< "error"<<endl;
  }
  else if(id == 0){
    int count = 0;
    while(1){
      sleep(1);
      cout<< "child... :"<<count<<endl;
      count++;
      if(count >= 10){
        break;
      }
    }
    exit(0);
  }
  else{
    int count = 0;
    while(1){
      sleep(1);
      cout<<"father..."<<endl;
      count++;
      if(count >= 15){
        break;
      }
    }
    wait(NULL);
  }
  cout << "hello world"<<endl;
}
