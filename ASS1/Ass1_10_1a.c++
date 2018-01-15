#include <bits/stdc++.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int main(){
	int pipe1[2],pipe2[2],pipe3[2];
	pid_t x;
	pipe(pipe1);
	pipe(pipe2);
	pipe(pipe3);
	int m=INT_MAX;
	x = fork();
	srand(time(NULL));	
	if(x==0){
		x = fork();	
		if(x!=0){
			vector<int> vec1(100);
			for(int i=0;i<100;i++){
				vec1[i] = rand()%1000+100;
			}
			sort(vec1.begin(), vec1.end());
			for(int i=0;i<100;i++){
				write(pipe1[1], &vec1[i], sizeof(vec1[i]));
			}
			write(pipe1[1], &m, sizeof(m));
		}
		else{
			x = fork();	
			if(x!=0){
				vector<int> vec1(100);
				for(int i=0;i<100;i++){
					vec1[i] = rand()%1000+100;
				}
				sort(vec1.begin(), vec1.end());
				for(int i=0;i<100;i++){
					write(pipe2[1], &vec1[i], sizeof(vec1[i]));
				}
				write(pipe2[1], &m, sizeof(m));
			}
			else{
				vector<int> vec1(100);
				for(int i=0;i<100;i++){
					vec1[i] = rand()%1000+100;
				}
				sort(vec1.begin(), vec1.end());
				for(int i=0;i<100;i++){
					write(pipe3[1], &vec1[i], sizeof(vec1[i]));
				}
				write(pipe3[1], &m, sizeof(m));
			}
		}
	}
	else{
		int a,b,c;
		read(pipe1[0], &a, sizeof(int));
		read(pipe2[0], &b, sizeof(int));
		read(pipe3[0], &c, sizeof(int));
		char arr[2]=" ";
		for(int i=0;i<300;i++){
			if(a<=b && a<=c){
				printf("%d ",a);				
				read(pipe1[0], &a, sizeof(int));
			}
			else if(b<=a && b<=c){
				printf("%d ",b);
				read(pipe2[0], &b, sizeof(int));
			}
			else{
				printf("%d ",c);
				read(pipe3[0], &c, sizeof(int));
			}
		}
		printf("\n");
	}

}
