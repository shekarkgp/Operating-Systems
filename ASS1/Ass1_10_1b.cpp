#include <iostream>
#include <bits/stdc++.h>
#include <sys/types.h>
#include <unistd.h>
#include <string> 

using namespace std;
int main(){
	pid_t x;
	
	while(1){
		
		char  line[1024];
		//cout<<"$Shell: ";
		gets(line);
		string str(line);
		if(str.compare("quit") == 0)
			exit(0);
		string temp;
		int f=0;
		vector<string> lis;
		for(int i=0;i<str.size();i++){
			//cout<<i<<endl;
			if(f==0 && str[i]!=' '){
				f=1;
				temp.clear();
				temp.push_back(str[i]);
			}
			else if(f==1 && str[i]!=' '){
				temp.push_back(str[i]);
			}
			else if(f==1 && str[i]==' '){
				lis.push_back(temp);
				temp.clear();
				//cout<<temp<<endl;
				f=0;
			}
		}
		if (temp.compare("")!=0)
			lis.push_back(temp);
		char *arg[lis.size()+1];
		for(int i=0;i<lis.size();i++){
			arg[i]=(char *) lis[i].c_str();
		}
		arg[lis.size()]=(char*) NULL;
		
		x = fork();
		if (x==0){			
			execvp(arg[0], arg);
			exit(0);
		}
	}
}
