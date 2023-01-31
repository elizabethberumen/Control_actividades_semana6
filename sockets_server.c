#include <winsock2.h>
#include<stdio.h>

char arr[10000][100];
void str_cpy(int indx,char aa[]){
	int i;
	for(i=0;aa[i]!='\n';i++){
		arr[indx][i]=aa[i];
	}
	arr[indx][i]='\0';
}
	int dohash(char aa[]){
		int i;
		int has=19497931;
		for(i=0;aa[i]!='\n' && aa[i]!='\0';i++){
			//printf("hs =%c ",aa[i]);
			has=has+((aa[i]*123791)/1313)*13913;
		}
		//printf("\n");
		return has%10000;
	}
		void load_file(){
			char aa[100];
			FILE *ptr=fopen("C:\\Users\\USER\\Desktop\\reply1.txt","r");//C:\Users\USER\Desktop
			while(1){
				fgets(aa,100,ptr);
				if(aa[0]=='E'){
					break;
				}
				int indx=dohash(aa);
				fgets(aa,100,ptr);
				str_cpy(indx,aa);
				//printf("filr    %d = %snm\n",indx,arr[indx]);
			}
			
			fclose(ptr);
		}
			void lowe_case(char buffer[]){
				int i;
				for(i=0;buffer[i]!='\0';i++){
					if(buffer[i]<96){
						buffer[i]=buffer[i]+32;
					}
				}
			}
				int reply(char buffer[]){
					lowe_case(buffer);
					return dohash(buffer);
				}
WSAStartup(MAKEWORD(2,0), &WSAData);


int main(int argc, char *argv[]) {
	load_file();
	WSADATA WSAData;
	SOCKET server, client;
	SOCKADDR_IN serverAddr, clientAddr;
	
	
	

	
	return 0;
}
	
	
	
	
	


