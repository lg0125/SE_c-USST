#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<direct.h>
//#include<string>
#include<map>
#include "data.h"

using namespace std;

const char c[7][30] = {{"../data/edge2015_1.csv"},{"../data/edge2015_2.csv"},{"../data/edge2016_1.csv"},{"../data/edge2016_2.csv"},{"../data/edge2017_1.csv"},{"../data/edge2017_2.csv"},{"../data/edge2018_1.csv"}};

map<Node,float> table;
char _data[5][10];

//string _data[5];

int main()
{
	FILE *fp = NULL;
	char *line=NULL;
	char *record=NULL;
	char buffer[1024];
	//char *_source = NULL,*_target = NULL;

	if((fp = fopen(c[0],"at+"))!=NULL)
	{
		fseek(fp,20L,SEEK_SET);
		
		int j = 0;
		
		while((line = fgets(buffer,sizeof(buffer),fp))!=NULL)
		{
			int i = 0;
			//Node node;
			record = strtok(line,",");
			//memcpy(_data[i++],record,strlen(record)+1);
			_data[i++] = record;
			printf("%s ",_data[i-1].c_str());
			
			//_data = record;
			
			//_data++;
			//sscanf(record,"%s",_data[i++]);
			//strcpy(node.source,record);
			//strcpy(_source,record);
			
			while(record != NULL)
			{
				printf("%s ",record);
				record = strtok(NULL,",");
				//_data[i++] = record;
				
				//memcpy(_data[i++],record,strlen(record)+1);
				//_data[i++] = record;
				//sscanf(record,"%s",_data[i++]);
			}
			
			//table.insert(pair<Node,float>(Node(_data[0],_data[1]),sigmoid(atof(_data[2]))));
			
			/*printf("%s ",_data[i-1]);
			
			record = strtok(NULL,",");
			//strcpy(node.target,record);
			//strcpy(_data[i++],record);

			printf("%s ",record);
			
			record = strtok(NULL,",");
			//table.insert(pair<Node,float>(Node(_source,_target),sigmoid(atof(record))));

			printf("%s ",record);*/
			
			//sscanf(line,"%s,%s,%s",_data[0],_data[1],_data[2]);
			
			/*for(int i=0;i<3;i++){
				if(i != 3-1){
					printf("%s ",_data[i]);
				}else{
					printf("%s\n",_data[i]);
				}
			}*/
			
			
			printf("\n");
			
			if(j == 20) break;
			j++;
		}
		fclose(fp);
		fp = NULL;
	}
	
	//printf("--------\n");

	/*for(map<Node,float>::iterator it = table.begin();it != table.end();it++){
		//printf("%s ",it->first.source);
		//printf("%s ",it->first.target);
		printf("%f\n",it->second);
	}*/
		


	return 0;
}
