/*
!!!!!!!!!!! 모든 함수들은 Dummy node는 제외하고 이용
!!!!!!!!!!! 단, Copy_List는 Dummy 포함 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define true 1
#define false 0
#define TITLE 0
#define ARTIST 1
#define ALBUM 2
#define GENRE 3

int num_total_songs;
int list_empty=1;
int plist_empty=1;
char whole_list[]="songs_database.txt";
char whole_plist[]="playlists_database.txt";

//(완성)
typedef struct list_node *list_ptr;
typedef struct list_node{
	list_ptr Llink;
	char artist[20];
	char title[25];
	char time[6];
	char album[40];
	int track_num;
	char Genre[20];
	list_ptr Rlink;
}list_node;

typedef struct plist_node *plist_ptr;
typedef struct plist_node{
	plist_ptr Llink;
	char plist_name[30];
	list_ptr songs_list;
	plist_ptr Rlink;
}plist_node;


list_ptr main_head=NULL;	//전체 노래들 리스트의 머리
plist_ptr plist_head=NULL;


void Init_list(list_ptr list);
void Insert_Node(list_ptr ins, list_ptr newnode);
void Insert_pNode(plist_ptr ins, plist_ptr newnode);

void Delete_Node(list_ptr dummy, list_ptr del_pos);
void Delete_pNode(plist_ptr dummy, plist_ptr del_pos);

///////// Node 하나 복사(완성) //////////
list_ptr Copy_Node(list_ptr input);
list_ptr Copy_List(list_ptr start); //Dummy 포함
list_ptr Delete_Dummy(list_ptr dummy);
void join_list(list_ptr head1,list_ptr head2);
void DeleteSong();
void DeleteSong_list(list_ptr list_head);

void Print_Node(list_ptr onenode);	// 노드 하나 출력(완성)
void Print_pNode(plist_ptr onenode);


void Read_List(list_ptr dummy, FILE* stream);
void Read_pList(plist_ptr dummy, FILE* stream);
void Update_List(list_ptr dummy, FILE* stream);
void Update_pList(plist_ptr dummy, FILE* stream);

// (완성), 시작이 dummy node면 안되요!
void Print_List(list_ptr dummy, list_ptr head,list_ptr final);
void Print_pList(plist_ptr dummy, plist_ptr head, plist_ptr final);

void Player_Function(list_ptr play_list);//Dummy 포함
void PlaySongs_Seq(list_ptr play_list);  //전체 노래 순차재생
void PlaySongs_Rand(list_ptr play_list,int num); //전체 노래 임의재생

//list_ptr Read_Playlist(char name[]); //Dummy 포함
void Make_Playlist();
void Copy_to_Another(list_ptr dummy);
void Add_to_Playlist(list_ptr input); //Dummy 포함
void ShowPlayLists_Choose_Playlist();
void ShowPlayLists_Delete_Playlist();

void Swap(list_node *a, list_node *b);
int Partition(list_node a[], int left, int right, int option, int check_updown);
void Quicksort(list_node a[], int left, int right, int option, int check_updown);

//함수 이름 이런식으로 짜기!
void ShowSongs_PlaySongs();
void ShowSongs_Sort_Copy(list_node a[]);
void ShowSongs_Sort_Title(int *check_updown);
void ShowSongs_Sort_Artist(int *check_updown);
void ShowSongs_Sort_Album(int *check_updown);
void ShowSongs_Sort_Genre(int *check_updown);

void ShowSongs_Search_Artist();
void ShowSongs_Search_Title();
void ShowSongs_Search_Album();
void ShowSongs_Search_Genre();

void ShowSongs();	//1번
void SearchSongs(list_ptr head);	//2번
void ShowPlayLists();	//3번
void AddSong();	//4번





/////////////////////////////////////////////////////////////////////////////////
int main()
{
	int user_input;
	int checkq=true, made=false;
	int i;
	

	list_ptr newone=NULL;	//Insert할 때 생성자
	list_ptr ins=NULL;		//Insert할 때 위치
		
	plist_ptr plist_newone=NULL;
	plist_ptr plist_ins=NULL;

	FILE* songs_database;
	FILE* playlists_database;

	//Dummy Node
	main_head=(list_ptr)malloc(sizeof(list_node));
	main_head->Rlink=main_head;
	main_head->Llink=main_head;
	//Dummy pNode
	plist_head=(plist_ptr)malloc(sizeof(plist_node));
	plist_head->Rlink=plist_head;
	plist_head->Llink=plist_head;

	//do{
	songs_database=fopen(whole_list,"r");
	playlists_database=fopen(whole_plist,"r");

	if(songs_database!=NULL){
		//Read_List(main_head,songs_database);
		list_empty=false;
		
		ins=main_head;
		/// 노래들을 가져옴
		for(i=0; !feof(songs_database);i++){
			newone=(list_ptr)malloc(sizeof(list_node));
			newone->Llink=NULL;
			newone->Rlink=NULL;
			
			fscanf(songs_database,"%s %s %s %s %d %s",newone->artist, newone->title, newone->time, newone->album, &newone->track_num, newone->Genre);
			Insert_Node(ins,newone);
			ins=ins->Rlink;
			newone=NULL;
		}
				
		num_total_songs=i;
		fclose(songs_database);
	}
	if(playlists_database!=NULL){
		/// 플레이리스트를 가져옴
		plist_empty=false;
		Read_pList(plist_head,playlists_database);
		fclose(playlists_database);
	}
	
	do{
		if(!list_empty){
			//(완성)
			do{
				printf("***********************************************[User InterFace]***********************************************\n");
				printf("*                                             1. Show All Songs                                              *\n");
				printf("*                                             2. Search the songs                                            *\n");
				printf("*                                             3. Show All Playlists                                          *\n");
				printf("*                                             4. Add New Song                                                *\n");
				printf("*                                             5. Delete Song                                                 *\n");
				printf("*                                             6. Quit                                                        *\n");
				printf("**************************************************************************************************************\n");
				printf("                                                    #Input :");
AGAIN:
				scanf("%d",&user_input);

				switch(user_input){
				case 1:
					system("cls");
					ShowSongs();
					break;
				case 2:
					system("cls");
					SearchSongs(main_head);
					break;
				case 3:
					system("cls");
					ShowPlayLists();
					break;
				case 4:
					system("cls");
					AddSong();
					break;
				case 5:
					system("cls");
					DeleteSong();
					break;
				case 6:
					system("cls");
					printf("*******************************************[Quit the Program]*******************************************\n");
					printf("*                                                                                                      *\n");
					printf("*                                              THANK YOU :)                                            *\n");
					printf("*                                                                                                      *\n");
					printf("********************************************************************************************************\n");
					checkq=false;
					break;
				default:
					printf("                                           Wrong Number! Please Try Again.\n");
					printf("                                                    #Input :");
					goto AGAIN;
				}		
			}while(checkq);

			//////<파일 저장>/////////////////////////////
			songs_database=fopen(whole_list,"w+");
			playlists_database=fopen(whole_plist,"r");
			
			Update_List(main_head,songs_database);
			fclose(songs_database);

			if(playlists_database!=NULL){
				fclose(playlists_database);
				playlists_database=fopen(whole_plist,"w+");
				Update_pList(plist_head,playlists_database);
				fclose(playlists_database);
			}

			
			
			made=false;
		}
		else{
			printf("!! There is no Songs at all. Please Add New Song.\n");
			system("pause");
			system("cls");
			AddSong(main_head);
			list_empty=false;
			made=true;
		}
	}while(!list_empty && made);
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////


void Init_list(list_ptr list)
{
	free(main_head);
	main_head = (list_ptr)malloc(sizeof(list_node));
	main_head->Rlink = main_head;
	main_head->Llink = main_head;
}
void Insert_Node(list_ptr ins, list_ptr newnode) //(완성)
{
	newnode->Llink=ins;
	newnode->Rlink=ins->Rlink; 
	ins->Rlink->Llink=newnode;
	ins->Rlink=newnode;
}
void Insert_pNode(plist_ptr ins, plist_ptr newnode) //(완성)
{
	newnode->Llink=ins;
	newnode->Rlink=ins->Rlink; 
	ins->Rlink->Llink=newnode;
	ins->Rlink=newnode;
}
/////////////// Node하나 삭제 ////////////////////////////////////////////////////
void Delete_Node(list_ptr dummy, list_ptr del_pos) //(완성) Dummy는 삭제 불가
{
	if(del_pos!=dummy){
		del_pos->Llink->Rlink=del_pos->Rlink;
		del_pos->Rlink->Llink=del_pos->Llink;
		free(del_pos);
	}		
}
void Delete_pNode(plist_ptr dummy, plist_ptr del_pos) //(완성) Dummy는 삭제 불가
{
	if(del_pos!=dummy){
		del_pos->Llink->Rlink=del_pos->Rlink;
		del_pos->Rlink->Llink=del_pos->Llink;
		free(del_pos);
	}		
}

///////// Node 하나 복사 /////////////////////////////////////////////////////////
list_ptr Copy_Node(list_ptr input) //(완성)
{
	list_ptr main_list=NULL;

	///////////// Return 위한 노드 하나 ///////////
	main_list=(list_ptr)malloc(sizeof(list_node));
	main_list->Llink=NULL;
	main_list->Rlink=NULL;

	//////////////노드 복사///////////////////////
	strcpy(main_list->artist, input->artist);
	strcpy(main_list->title, input->title);
	strcpy(main_list->time, input->time);
	strcpy(main_list->album, input->album);
	main_list->track_num=input->track_num;
	strcpy(main_list->Genre, input->Genre);

	return main_list;
}
/////리스트를 쭉 복사(Dummy 포함)/////////
list_ptr Copy_List(list_ptr start) //(완성) Dummy 포함
{
	list_ptr copied_temp=NULL;
	list_ptr copied_list=NULL;
	list_ptr copied_pos=NULL;
	list_ptr temp=NULL;

	/////////// Dummy Node 하나 생성 ////////////////
	copied_list=(list_ptr)malloc(sizeof(list_node));
	copied_list->Llink=copied_list;
	copied_list->Rlink=copied_list;
	copied_pos=copied_list;

	///// Dummy는 건너뛰기 ////

	temp=start->Rlink;
	while(temp!=start){
		copied_temp=Copy_Node(temp);
		Insert_Node(copied_pos, copied_temp);

		//초기화
		copied_pos=copied_pos->Rlink;
		temp=temp->Rlink;
		copied_temp=NULL;
	}
	return copied_list;
}
///// 복사해서 삭제하므로 걱정 no /////
list_ptr Delete_Dummy(list_ptr dummy)
{
	list_ptr temp=NULL;
	list_ptr return_temp=NULL;

	temp=Copy_List(dummy);
	temp=dummy;
	return_temp=dummy->Rlink;
	
	temp->Llink->Rlink = temp->Rlink;
	temp->Rlink->Llink = temp->Llink;
	dummy->Rlink=NULL;
	dummy->Llink=NULL;
	free(temp);

	return return_temp;
}
/////// dummy1과 head를 이어 붙임 //////////
void join_list(list_ptr head1,list_ptr head2)
{
	list_ptr dummy2=NULL;
	dummy2=Copy_List(head2);

	head1->Llink->Rlink = dummy2->Rlink;
	dummy2->Rlink->Llink = head1->Llink;

	head1->Llink = dummy2->Llink;
	dummy2->Llink->Rlink = head1;

	dummy2->Rlink=NULL;
	dummy2->Llink=NULL;

	free(dummy2);	
}

void DeleteSong()
{
	char song_title[25];
	char song_artist[20];
	
	char tab_artist[9]="<Artist>";
	char tab_title[8]="<Title>";
	char tab_time[7]="<Time>";
	char tab_album[8]="<Album>";
	char tab_track_num[9]="<#Track>";
	char tab_Genre[8]="<Genre>";
	
	char check;
	
	list_ptr temp = NULL;

	printf("***************************************************[Songs]***************************************************\n");
	printf("*%-20s %-24s %-4s %-31s %-s %-13s*\n",tab_artist,tab_title,tab_time,tab_album,tab_track_num,tab_Genre);
	
	Print_List(main_head,main_head->Rlink,main_head);
	printf("*************************************************************************************************************\n\n");
	
	
	
	printf("Input the title of the song you want to delete : ");
	scanf("%s",song_title);
	printf("Input the artist of the song you want to delete : ");
	scanf("%s",song_artist);
	
	temp = main_head->Rlink;
	
	while(temp != main_head)
	{
		if(!strcmp(temp->title,song_title) && !strcmp(temp->artist,song_artist))
		{
			system("cls");
			
			printf("***************************************************[Song]****************************************************\n");	
			printf("*%-20s %-24s %-4s %-31s %-s %-13s*\n",tab_artist,tab_title,tab_time,tab_album,tab_track_num,tab_Genre);
			Print_Node(temp);
			printf("*************************************************************************************************************\n\n");
			
			printf("Do you really want to delete this song(y/n)? : ");
			fflush(stdin);
			scanf("%c",&check);
			
			if(check == 'y') {
				Delete_Node(main_head,temp);
			}
			
			else if (check == 'n'){
				printf("You canceled.\n");
				system("pause");
				system("cls");				
				return;
			}
			system("cls");
			break;
		}
		
		temp = temp->Rlink;
		
		if(temp == main_head){
			printf("\nThe input title or artist is uncorrect. Please try again! \n\n");
			system("pause");
		}
	}
	
	system("cls");
	
	if(main_head->Rlink == main_head){
		printf("!! There is no Songs at all. Please Add New Song.\n");
		system("pause");
		system("cls");
		AddSong(main_head);
	}
}


void DeleteSong_list(list_ptr list_head)
{
	char song_title[25];
	char song_artist[20];
	
	char tab_artist[9]="<Artist>";
	char tab_title[8]="<Title>";
	char tab_time[7]="<Time>";
	char tab_album[8]="<Album>";
	char tab_track_num[9]="<#Track>";
	char tab_Genre[8]="<Genre>";
	
	char check;
	
	list_ptr pos=NULL;
	list_ptr temp = NULL;
	list_ptr temp2 = NULL;

	printf("***************************************************[Songs]***************************************************\n");
	printf("*%-20s %-24s %-4s %-31s %-s %-13s*\n",tab_artist,tab_title,tab_time,tab_album,tab_track_num,tab_Genre);
	//출력
	Print_List(list_head,list_head->Rlink,list_head);
	printf("*************************************************************************************************************\n\n");
	
	
	printf("Input the Title of the Song You Want to Delete : ");
	scanf("%s",song_title);
	printf("Input the Artist of the Song you Want to Delete : ");
	scanf("%s",song_artist);
	
	temp = list_head->Rlink;
	temp2 = main_head->Rlink;
	
	while(temp != list_head)
	{
		if(!strcmp(temp->title,song_title) && !strcmp(temp->artist,song_artist))
		{
			system("cls");
			
			printf("***************************************************[Song]****************************************************\n");	
			printf("*%-20s %-24s %-4s %-31s %-s %-13s*\n",tab_artist,tab_title,tab_time,tab_album,tab_track_num,tab_Genre);
			Print_Node(temp);
			printf("*************************************************************************************************************\n\n");
			
			printf("Do you Really Want to Delete this Song from This List(y/n)? :");
			fflush(stdin);
			scanf("%c",&check);
			
			if(check == 'y') {		
				pos=temp->Llink;
				Delete_Node(list_head,temp);
				temp=pos->Rlink;
				printf("Successfully Deleted from this List!\n");
			}
			
			else if (check == 'n'){
				printf("You Canceld to Delete this Songs from this list..\n");		
				system("pause");
				system("cls");	
				return;
			}
			
			printf("Do you Want to Delete this Song from the Main List too (y/n)? :");
			fflush(stdin);
			scanf("%c",&check);
			
			if(check == 'y') {
				pos=main_head->Rlink;

				while(pos!=main_head){
					if(strcmp(pos->title,song_title)==0 && strcmp(pos->artist,song_artist)==0){
						Delete_Node(main_head, pos);
						printf("Successfully Deleted from the Main List!\n");
						system("pause");
						system("cls");
						return;
					}
					pos=pos->Rlink;
				}
			}
			
			else if (check == 'n'){
				printf("You Canceled to Delete the Song from the Main List.\n");
				system("pause");
				system("cls");				
				return;
			}
		}
		
		temp = temp->Rlink;
		
		if(temp == list_head)
		{
			printf("\nThe input title or artist is uncorrect. Please try again! \n\n");
			system("pause");
			system("cls");
			
		}
	}
}


/////////////////////////////////////////////////////////////////////////////////
void Print_Node(list_ptr onenode)
{
	fprintf(stdout," %-20s %-25s %-5s %-35s %-5d %-12s\n",onenode->artist, onenode->title, onenode->time, onenode->album, onenode->track_num, onenode->Genre);
}
void Print_pNode(plist_ptr onenode)
{
	printf("                                                     %s\n",onenode->plist_name);
}
void Print_List(list_ptr dummy,list_ptr head,list_ptr final)
{
	list_ptr temp=NULL;

	temp=head;
	Print_Node(temp);
	temp=temp->Rlink;

	while(temp!=final){
		Print_Node(temp);
		temp=temp->Rlink;
	}
}
void Print_pList(plist_ptr dummy, plist_ptr head, plist_ptr final)
{
	plist_ptr temp=NULL;
	
	temp=head;
	Print_pNode(temp);
	temp=temp->Rlink;

	while(temp!=final){
		Print_pNode(temp);
		temp=temp->Rlink;
	}	
}

/////<파일스트림을 변수로 읽어옴> (FILE* stream은 "r"로 오픈된 상태, Dummy에 이어짐)////
void Read_List(list_ptr dummy, FILE* stream)
{
	int i;
	list_ptr newone=NULL;
	list_ptr ins=NULL;

	ins=dummy;
	for(i=0; !feof(stream);i++){
		newone=(list_ptr)malloc(sizeof(list_node));
		newone->Llink=NULL;
		newone->Rlink=NULL;

		fscanf(stream,"%s %s %s %s %d %s",newone->artist, newone->title, newone->time, newone->album, &newone->track_num, newone->Genre);
		Insert_Node(ins,newone);
		ins=ins->Rlink;
		newone=NULL;
	}
}
void Read_pList(plist_ptr dummy, FILE* stream)
{
	int i;
	plist_ptr newone=NULL;
	plist_ptr ins=NULL;

	ins=dummy;
	for(i=0; !feof(stream);i++){
		newone=(plist_ptr)malloc(sizeof(plist_node));
		newone->Llink=NULL;
		newone->Rlink=NULL;

		fscanf(stream,"%s",newone->plist_name);
		Insert_pNode(ins,newone);
		ins=ins->Rlink;
		newone=NULL;
	}
}

/////<리스트 전체를 텍스트에 새로 씀> (FILE* stream은 "w+"로 오픈된 상태)//////////////
void Update_List(list_ptr dummy, FILE* stream)
{
	list_ptr pos=NULL;
	pos=dummy->Rlink;

	while(pos!=dummy->Llink){
		fprintf(stream,"%s %s %s %s %d %s\n",pos->artist,pos->title,pos->time,pos->album,pos->track_num,pos->Genre);
		pos=pos->Rlink;
	}
	fprintf(stream,"%s %s %s %s %d %s",pos->artist,pos->title,pos->time,pos->album,pos->track_num,pos->Genre);
}
void Update_pList(plist_ptr dummy, FILE* stream)
{
	plist_ptr pos=NULL;
	pos=dummy->Rlink;

	while(pos!=dummy->Llink){
		fprintf(stream,"%s\n",pos->plist_name);
		pos=pos->Rlink;
	}
	fprintf(stream,"%s",pos->plist_name);
}


///// Dummy 포함//////////////////////////////////////////////////////////////////
void Player_Function(list_ptr play_list)
{
	int player_input;
	int quit=true;
	list_ptr temp_list=NULL;
	list_ptr pos=NULL;
	//
	list_ptr nodummy=NULL;

	temp_list=Copy_List(play_list);	
	// Dummy 삭제 //
	nodummy=Delete_Dummy(temp_list);
	pos=nodummy;
	do{
		printf("                                **************** <Now Playing> ****************\n");
		printf("                                *          %-20s                \n",pos->title);
		printf("                                *          %-24s            \n",pos->artist);
		printf("                                *          %-4s                                \n",pos->time);
		printf("                                *          %-31s     \n",pos->album);
		printf("***************************************************[Songs]***************************************************\n");
		if(pos->Rlink==pos)
		{}
		else if(nodummy->Rlink->Rlink==nodummy)
			Print_Node(pos->Rlink);
		else
			Print_List(NULL,pos->Rlink,pos);
		printf("**************************************************[Options]**************************************************\n");
		printf("                                    1.Previous     2.Next      3.Quit                                       *\n");

PLAYER_AGAIN:
		printf("#Input :");
		scanf("%d",&player_input);
		switch(player_input){
		case 1: //Previous
			system("cls");
			pos=pos->Llink;			
			break;
		case 2: //Next
			system("cls");
			pos=pos->Rlink;
			break;
		case 3: //Quit
			system("cls");
			quit=false;
			break;
		default:
			printf("                                   Wrong Number! Please Try Again.\n");
			printf("                                                #Input :");
			goto PLAYER_AGAIN;
		}

	}while(quit);
}
/////순차&임의재생(Dummy 포함해서 줌)//////
void PlaySongs_Seq(list_ptr play_list)
{
	Player_Function(play_list);
}
/////play_list (Dummy 포함), num(play_list의 노래갯수) 
void PlaySongs_Rand(list_ptr play_list,int num)
{
	int i,j,rand_num;
	list_ptr mmain=NULL; // 새로만들 첫 헤드
	list_ptr pos=NULL;
	list_ptr temp=NULL;
	list_ptr copied_playlist=NULL;

	//복사
	copied_playlist = Copy_List(play_list);
	pos = copied_playlist->Rlink;

	mmain=(list_ptr)malloc(sizeof(list_node));
	mmain->Rlink=mmain;
	mmain->Llink=mmain;
		
	srand((unsigned)time(NULL));
	for(i=0;i<num;i++){			
		rand_num=rand()%num;
		for(j=0;j<rand_num;j++){
			pos=pos->Rlink->Rlink; //많이 섞어주기 위해 두번씩 넘김
		}
		if(pos==copied_playlist)
				pos=pos->Rlink;

		temp=Copy_Node(pos);

		Insert_Node(mmain,temp); //새로 추가
		Delete_Node(copied_playlist,pos);//기존에서 삭제

		/// Initialize
		temp=NULL;
		pos=copied_playlist;
	}
	/////////////////////////////////////////////////////
	Player_Function(mmain);
}
/////////////////////////////////////////////////////////////////////////////////
void Make_Playlist()
{
	char pname[30],temp_name[30],okay;
	int checkk=true;
	plist_ptr newpnode=NULL;
	plist_ptr pos=NULL;
	FILE* new_plist=NULL;
	FILE* playlists_database;

	playlists_database=fopen(whole_plist,"w+");

	printf("************************************************[Make Playlist]************************************************\n");


	printf("                       New Playlist Name(Replace ' ' to '_') :");
	scanf("%s",pname);
	printf("Are you Sure '%s'? (y/n) :",pname);
	fflush(stdin);
	scanf("%c",&okay);
	system("cls");
	if(okay=='n'){
		printf("You Canceled.\n");
		goto MAKE_PLAYLIST_AGAIN;
	}
	else{
		strcpy(temp_name,pname);
		strcat(temp_name,".txt");
		new_plist=fopen(temp_name,"w+"); //재생목록 이름 생성
		newpnode=(plist_ptr)malloc(sizeof(plist_node));
		newpnode->Rlink=NULL;
		newpnode->Llink=NULL;
		strcpy(newpnode->plist_name,pname);

		pos=plist_head;

		do{
			if(strcmp(pos->Rlink->plist_name,pname)<0){
				pos=pos->Rlink;
			}
			else{
				Insert_pNode(pos,newpnode);
				checkk=false;
			}
		}while(checkk);
	}
	
	Update_pList(plist_head,playlists_database);

	fclose(new_plist);
	fclose(playlists_database);
	printf("The New Playlist '%s' is made!\n",pname);
MAKE_PLAYLIST_AGAIN:
	system("pause");
	system("cls");
}
void Copy_to_Another(list_ptr dummy)
{
	FILE* temp_open;
	char temp_name[20];
	int exist=false;
	plist_ptr pos=NULL;
	list_ptr dummy2=NULL;

	printf("********************************************************************\n");
	Print_pList(plist_head,plist_head->Rlink,plist_head);
	printf("********************************************************************\n");
	printf("Input Another Playlist :");
	scanf("%s",temp_name);
	pos=plist_head->Rlink;
	if(strcmp(pos->plist_name,temp_name)==0)
		exist=true;
	pos=pos->Rlink;
	while(pos!=plist_head && !exist){
		if(strcmp(pos->plist_name,temp_name)==0)
			exist=true;
		pos=pos->Rlink;
	}

	if(exist){
		strcat(temp_name,".txt");
		temp_open=fopen(temp_name,"r");
		dummy2=(list_ptr)malloc(sizeof(list_node));
		dummy2->Rlink=dummy2;
		dummy2->Llink=dummy2;
		if(dummy2->Rlink->track_num>0)
			Read_List(dummy2, temp_open);

		join_list(dummy2,dummy);
		fclose(temp_open);

		temp_open=fopen(temp_name,"w+");
		Update_List(dummy2,temp_open);
		fclose(temp_open);
		
		
		Print_List(dummy2,dummy2->Rlink,dummy2);
		printf("Successfully Joined!\n");
		system("pause");
		system("cls");
	}
	else{
		printf("These is no playlist '%s'.\n",temp_name);
		system("pause");
		system("cls");
	}
}
//Dummy 포함
void Add_to_Playlist(list_ptr input)
{
	int i, checkk=true, fcheck=false;
	char add_playlist_input[30];
	FILE* aplist;

	list_ptr newone=NULL;
	list_ptr ins=NULL;
	list_ptr pos=NULL;
	list_ptr empty_node=NULL;
	list_ptr input_temp=NULL;

	list_ptr temp=NULL;
	plist_ptr plist_pos=NULL;
	
	
	if(plist_head->Rlink!=plist_head){
		
		plist_pos = plist_head->Rlink;
		Print_pList(plist_head,plist_head->Rlink,plist_head);
		temp=Delete_Dummy(input);
		printf("***********************************************[User InterFace]***********************************************\n");
		do{
			printf("Which List do you want? :");
			scanf("%s",add_playlist_input);
			for(i=0 ; plist_pos!=plist_head ; i++){
				if(strcmp(plist_pos->plist_name,add_playlist_input)==0){
					plist_pos->songs_list=temp;
					checkk=false;
					fcheck=true;
				}
				plist_pos=plist_pos->Rlink;
			}

			if(fcheck==false){ //찾지 못함.
		printf("                                          There is no '%s' playlist.\n",add_playlist_input);
				checkk=false;
				system("pause");
			}
			else{
				strcat(add_playlist_input,".txt");
				aplist=fopen(add_playlist_input,"a+");

				////// 처음 하나 추가 /////
				empty_node=temp;
				fprintf(aplist,"\n%s %s %s %s %d %s",empty_node->artist, empty_node->title, empty_node->time, empty_node->album, empty_node->track_num, empty_node->Genre);
				empty_node=empty_node->Rlink;

				while(empty_node!=temp){
					fprintf(aplist,"\n%s %s %s %s %d %s",empty_node->artist, empty_node->title, empty_node->time, empty_node->album, empty_node->track_num, empty_node->Genre);
					empty_node=empty_node->Rlink;
				}
				fclose(aplist);
				printf("Mission Complete!\n");
				system("pause");
				////////////////////////////////////////////////
			}
		}while(checkk);
	}
	else{
		printf("There is no Playlist. Please Make a list first.\n");
		system("pause");
		Make_Playlist();
	}
}
void ShowPlayLists_Choose_Playlist()
{
	char plist_name[20];
	char plist_temp[20];
	FILE* temp_stream;
	int exist=false, choose_playlist_input;
	plist_ptr pos=NULL;
	list_ptr temp=NULL;
	
	temp=(list_ptr)malloc(sizeof(list_node));
	temp->Rlink=temp;
	temp->Llink=temp;
	
	printf("****************************************<Playlists>*****************************************************\n");
	Print_pList(plist_head,plist_head->Rlink,plist_head);
	printf("********************************************************************************************************\n");
	printf("                               Playlist :");
	scanf("%s",plist_name);
	system("cls");
	pos=plist_head->Rlink;
	if(strcmp(pos->plist_name,plist_name)==0)
		exist=true;
	pos=pos->Rlink;
	while(pos!=plist_head && !exist){
		if(strcmp(pos->plist_name,plist_name)==0)
			exist=true;
		pos=pos->Rlink;
	}
	if(exist){
		pos=pos->Llink;
		strcpy(plist_temp,plist_name);
		strcat(plist_temp,".txt");
		temp_stream=fopen(plist_temp,"r");
		Read_List(temp,temp_stream);
		
		//파일이 비었을 경우 (~<0)
		if(temp->Rlink->track_num>0){
			printf("*************************************************************************************************************\n");
			Print_List(temp,temp->Rlink,temp);
			fclose(temp_stream);

			printf("*************************************************************************************************************\n");
			printf("     1.Play the list  2.Copy to Another Playlist  3.Delete a Song  4.Go to Upper Menu\n");
			printf("           #Input :");

CHOOSE_PLAYLIST_AGAIN:
			scanf("%d",&choose_playlist_input);
			switch(choose_playlist_input){
			case 1:
				system("cls");
				Player_Function(temp);
				break;
			case 2:
				system("cls");
				Copy_to_Another(temp);
				break;
			case 3:
				system("cls");
				DeleteSong_list(temp);
				temp_stream=fopen(plist_temp,"w+");
				Update_List(temp,temp_stream);
				fclose(temp_stream);
				break;
			case 4:	
				system("cls");
				break;
			default:
				printf("              I think the number is incorrect. Please Input Correctly :");
				goto CHOOSE_PLAYLIST_AGAIN;
			}
		}

		else{
			fclose(temp_stream);
			printf("************************************<Warning>**********************************************\n");
			printf("                              This list is Empty!\n");
			fflush(stdin);
			system("pause");
			system("cls");
		}
	}
	else{
		printf("There isn't '%s' list.\n",plist_name);
	}
}
void ShowPlayLists_Delete_Playlist(){

	char deleted_plist[20];
	int exist=false,not_deleted;

	plist_ptr pos=NULL;


	printf("*************************************************[Delete Playlist]**********************************************\n");
	printf("                                            #Playlist :");
	scanf("%s",deleted_plist);

	pos=plist_head->Rlink;
	if(strcmp(pos->plist_name,deleted_plist)==0)
		exist=true;
	pos=pos->Rlink;
	while(pos!=plist_head && !exist){
		if(strcmp(pos->plist_name,deleted_plist)==0)
			exist=true;
		pos=pos->Rlink;
	}
	pos=pos->Llink; //제자리로 돌리기(한번 더 진행하게 됨)
	
	if(exist){
		strcat(deleted_plist,".txt");
		not_deleted=remove(deleted_plist);
		Delete_pNode(plist_head,pos);

		if(!not_deleted){
			fflush(stdin);
			printf("Successfully Deleted!\n");
			system("pause");
			system("cls");
		}
		else{
			fflush(stdin);
			printf("Falied to Remove Text File.\n");
			printf("pause");
			system("cls");
		}
	}
	else{
		printf("***************************************************[Warning]****************************************************\n");
		printf("                                            There is no '%s' File!\n",deleted_plist);
		printf("****************************************************************************************************************\n");
		system("pause");
		system("cls");
	}	
}
////////////////////<정렬 때 필요>//////////////////////////////////////////////////
void Swap(list_node *a, list_node *b)
{
	list_node temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
int Partition(list_node a[], int left, int right, int option, int check_updown)
{
	int i, j;
	int pivot;

	pivot = left; i = left;
	
	if (option == 0){
		for (j = left; j < right; j++){
			if (check_updown % 2 == 0 && strcmp(a[j].title, a[pivot].title) == 1){
				i++;
				Swap(&a[j], &a[i]);
			}
			else if (check_updown % 2 == 1 && strcmp(a[j].title, a[pivot].title) == -1){
				i++;
				Swap(&a[j], &a[i]);
			}
		}
		if (strcmp(a[i].title, a[pivot].title) != 0){
			Swap(&a[pivot], &a[i]);
		}
		return i;
	}
	else if (option == 1){
		for (j = left; j < right; j++){
			if (check_updown % 2 == 0 && strcmp(a[j].artist, a[pivot].artist) == 1){
				i++;
				Swap(&a[j], &a[i]);
			}
			else if (check_updown % 2 == 1 && strcmp(a[j].artist, a[pivot].artist) == -1){
				i++;
				Swap(&a[j], &a[i]);
			}
		}
		if (strcmp(a[i].artist, a[pivot].artist) != 0){
			Swap(&a[pivot], &a[i]);
		}
		return i;
	}
	else if (option == 2){
		for (j = left; j < right; j++){
			if (check_updown % 2 == 0 && strcmp(a[j].album, a[pivot].album) == 1){
				i++;
				Swap(&a[j], &a[i]);
			}
			else if (check_updown % 2 == 1 && strcmp(a[j].album, a[pivot].album) == -1){
				i++;
				Swap(&a[j], &a[i]);
			}
		}
		if (strcmp(a[i].album, a[pivot].album) != 0){
			Swap(&a[pivot], &a[i]);
		}
		return i;
	}
	else{
		for (j = left; j < right; j++){
			if (check_updown % 2 == 0 && strcmp(a[j].Genre, a[pivot].Genre) == 1){
				i++;
				Swap(&a[j], &a[i]);
			}
			else if (check_updown % 2 == 1 && strcmp(a[j].Genre, a[pivot].Genre) == -1){
				i++;
				Swap(&a[j], &a[i]);
			}
		}
		if (strcmp(a[i].Genre, a[pivot].Genre) != 0){
			Swap(&a[pivot], &a[i]);
		}
		return i;
	}
}
void Quicksort(list_node a[], int left, int right, int option, int check_updown)
{
	int p;

	if (right - left>0){
		p = Partition(a, left, right, option, check_updown);
		Quicksort(a, left, p, option, check_updown);
		Quicksort(a, p + 1, right, option, check_updown);
	}
}
////////////////////<정렬관련>//////////////////////////////////////////////////////
void ShowSongs_PlaySongs()
{
	int playsongs_input;
	int checkq=true;
	do{
		printf("                                        ****************************************                             \n");
		printf("                                        *1.I'd like to play songs \'Sequently\'*\n");
		printf("                                        *2.I'd like to play songs \'Randomly\'.*\n");
		printf("                                        *3.Sorry. I \'Changed My Mind.\'      .*\n");
		printf("                                        ****************************************                             \n");
AGAIN1_1:
		printf("                                                       # Input :");
		scanf("%d",&playsongs_input);
		switch(playsongs_input){
		case 1:
			system("cls");
			PlaySongs_Seq(main_head);
			checkq=false;
			break;
		case 2:
			system("cls");
			PlaySongs_Rand(main_head,num_total_songs);
			checkq=false;
			break;
		case 3:
			checkq=false;
			system("cls");
			break;
		default:
			printf("                                           Wrong Number! Please Try Again.\n");
			goto AGAIN1_1;
		}
	}while(checkq);
}
void ShowSongs_Sort_Copy(list_node a[]){
	list_ptr temp=NULL;
	list_ptr copy_temp = (list_ptr)malloc(sizeof(list_node));
	int i;

	temp = main_head->Rlink;
	for (i = 0; i < num_total_songs; i++){
		copy_temp = Copy_Node(temp);
		strcpy(a[i].artist, copy_temp->artist);
		strcpy(a[i].title, copy_temp->title);
		strcpy(a[i].time, copy_temp->time);
		strcpy(a[i].album, copy_temp->album);
		a[i].track_num = copy_temp->track_num;
		strcpy(a[i].Genre, copy_temp->Genre);
		temp = temp->Rlink;
	}
}
void ShowSongs_Sort_Title(int *check_updown)
{
	list_node *a = (list_node*)malloc(sizeof(list_node)*num_total_songs);
	int i;

	ShowSongs_Sort_Copy(a);
	Quicksort(a, 0, num_total_songs, TITLE, check_updown);
	Init_list(main_head);

	for (i = 0; i < num_total_songs; i++)
		Insert_Node(main_head, &a[i]);

}
void ShowSongs_Sort_Artist(int *check_updown)
{
	list_node *a = (list_node*)malloc(sizeof(list_node)*num_total_songs);
	int i;

	ShowSongs_Sort_Copy(a);
	Quicksort(a, 0, num_total_songs, ARTIST, check_updown);
	Init_list(main_head);

	for (i = 0; i < num_total_songs; i++)
		Insert_Node(main_head, &a[i]);

}
void ShowSongs_Sort_Album(int *check_updown)
{
	list_node *a = (list_node*)malloc(sizeof(list_node)*num_total_songs);
	int i;

	ShowSongs_Sort_Copy(a);
	Quicksort(a, 0, num_total_songs, ALBUM, check_updown);
	Init_list(main_head);

	for (i = 0; i < num_total_songs; i++)
		Insert_Node(main_head, &a[i]);
}
void ShowSongs_Sort_Genre(int *check_updown)
{
	list_node *a = (list_node*)malloc(sizeof(list_node)*num_total_songs);
	int i;

	ShowSongs_Sort_Copy(a);
	Quicksort(a, 0, num_total_songs, GENRE, check_updown);
	Init_list(main_head);

	for (i = 0; i < num_total_songs; i++)
		Insert_Node(main_head, &a[i]);

}
/////<검색관련>///////////////////////////////////////////////////////////////////
void ShowSongs_Search_Artist(list_ptr head) //////
{
	char tab_artist[9]="<Artist>";
	char tab_title[8]="<Title>";
	char tab_time[7]="<Time>";
	char tab_album[8]="<Album>";
	char tab_track_num[9]="<#Track>";
	char tab_Genre[8]="<Genre>";
	char artist_serach[20];
	int count = 0, asearch_input,checkk=true,re=true;
	list_ptr temp = NULL;
	list_ptr newone = NULL;
	list_ptr newhead = NULL;
	list_ptr ins = NULL;

	newhead=(list_ptr)malloc(sizeof(list_node));
	newhead->Rlink=newhead;
	newhead->Llink=newhead;

	temp = head->Rlink;

	printf("* Please Replace ' '(Space) to '_'.\n");
	printf("Enter the name of the artist : ");
	scanf("%s", artist_serach);

	ins = newhead;

	while(temp != head)
	{
		if(!strcmp(temp->artist,artist_serach))
		{
			newone=(list_ptr)malloc(sizeof(list_node));

			strcpy(newone->artist,temp->artist);
			strcpy(newone->title,temp->title);
			strcpy(newone->time,temp->time);
			strcpy(newone->album,temp->album);
			newone->track_num = temp->track_num;
			strcpy(newone->Genre,temp->Genre);

			Insert_Node(ins,newone);
			newone=NULL;
			count++;
		}

		temp = temp -> Rlink;
	}

	printf("\nWe found %d songs that match the Artist.\n\n",count);
	printf("***************************************************[Songs]***************************************************\n");
	printf("*%-20s %-24s %-4s %-31s %-s %-13s*\n",tab_artist,tab_title,tab_time,tab_album,tab_track_num,tab_Genre);

	if(count == 0)
	{
		printf("*                                                                                                           *\n");
		printf("*                                           No Matched Artist :(                                            *\n");
		printf("*                                                                                                           *\n");
		printf("*************************************************************************************************************\n");
		re=false;
		system("pause");
	}
	else if(count == 1){
		Print_Node(newhead->Rlink);
	}
	else
		Print_List(newhead,newhead->Rlink,newhead);
	if(re){
		// newnode에 검색 결과가 저장
		printf("*************************************************************************************************************\n");
		do{
			printf("*                 1. Play the Song         2. Add to Playlist            3. Quit                        *\n");
			printf("*************************************************************************************************************\n");
			printf("#input :"); 
ASEARCH:		
			scanf("%d",&asearch_input);
			switch(asearch_input){
			case 1: //Play song
				checkk=false;
				system("cls");
				Player_Function(newhead);
				break;
			case 2: //Add to playlist
				checkk=false;
				system("cls");
				Add_to_Playlist(newhead);
				break;
			case 3:
				checkk=false;
				system("cls");
				break;
			default:
				printf("Wrong Number! Please Input Again :");
				goto ASEARCH;
			}
		}while(checkk);
	}
	else{			
	}
	system("cls");
}
void ShowSongs_Search_Title(list_ptr head) //////
{
	char tab_artist[9]="<Artist>";
	char tab_title[8]="<Title>";
	char tab_time[7]="<Time>";
	char tab_album[8]="<Album>";
	char tab_track_num[9]="<#Track>";
	char tab_Genre[8]="<Genre>";
	char title_serach[25];
	int count = 0,tsearch_input,checkk=true,re=true;
	list_ptr temp = NULL;
	list_ptr newone = NULL;
	list_ptr newhead = NULL;
	list_ptr ins = NULL;

	newhead=(list_ptr)malloc(sizeof(list_node));
	newhead->Rlink=newhead;
	newhead->Llink=newhead;

	temp = head->Rlink;

	printf("* Please Replace ' '(Space) to '_'.\n");
	printf("Enter the title : ");
	scanf("%s", title_serach);

	ins = newhead;

	while(temp != head)
	{
		if(!strcmp(temp->title,title_serach))
		{
			newone=(list_ptr)malloc(sizeof(list_node));

			strcpy(newone->artist,temp->artist);
			strcpy(newone->title,temp->title);
			strcpy(newone->time,temp->time);
			strcpy(newone->album,temp->album);
			newone->track_num = temp->track_num;
			strcpy(newone->Genre,temp->Genre);

			Insert_Node(ins,newone);
			newone=NULL;
			count++;
		}

		temp = temp -> Rlink;
	}

	printf("\nWe found %d songs that match the Title.\n\n",count);
	printf("***************************************************[Songs]***************************************************\n");
	printf("*%-20s %-24s %-4s %-31s %-s %-13s*\n",tab_artist,tab_title,tab_time,tab_album,tab_track_num,tab_Genre);

	if(count == 0)
	{
		printf("*                                                                                                           *\n");
		printf("*                                           No Matched Title :(                                             *\n");
		printf("*                                                                                                           *\n");
		printf("*************************************************************************************************************\n");
		re=false;
		system("pause");
	}
	else if(count == 1) Print_Node(newhead->Rlink);
	else Print_List(newhead,newhead->Rlink,newhead);
	if(re){
		// newnode에 검색 결과가 저장
		printf("*************************************************************************************************************\n");
		do{
			printf("*                 1. Play the Song         2. Add to Playlist            3. Quit                        *\n");
			printf("*************************************************************************************************************\n");
			printf("#input :"); 
TSEARCH:		
			scanf("%d",&tsearch_input);
			switch(tsearch_input){
			case 1: //Play song
				checkk=false;
				system("cls");
				Player_Function(newhead);
				break;
			case 2: //Add to playlist
				checkk=false;
				system("cls");
				Add_to_Playlist(newhead);

				break;
			case 3:
				checkk=false;
				system("cls");


				break;
			default:
				printf("Wrong Number! Please Input Again :");
				goto TSEARCH;
			}
		}while(checkk);
	}
	else{			
	}
	system("cls");
}
void ShowSongs_Search_Album(list_ptr head) //////
{
	char tab_artist[9]="<Artist>";
	char tab_title[8]="<Title>";
	char tab_time[7]="<Time>";
	char tab_album[8]="<Album>";
	char tab_track_num[9]="<#Track>";
	char tab_Genre[8]="<Genre>";
	char album_serach[40];
	int count = 0, bsearch_input,checkk=true,re=true;
	list_ptr temp = NULL;
	list_ptr newone = NULL;
	list_ptr newhead = NULL;
	list_ptr ins = NULL;

	newhead=(list_ptr)malloc(sizeof(list_node));
	newhead->Rlink=newhead;
	newhead->Llink=newhead;

	temp = head->Rlink;

	printf("* Please Replace ' '(Space) to '_'.\n");
	printf("Enter the name of the album : ");
	scanf("%s", album_serach);

	ins = newhead;

	while(temp != head)
	{
		if(!strcmp(temp->album,album_serach))
		{
			newone=(list_ptr)malloc(sizeof(list_node));

			strcpy(newone->artist,temp->artist);
			strcpy(newone->title,temp->title);
			strcpy(newone->time,temp->time);
			strcpy(newone->album,temp->album);
			newone->track_num = temp->track_num;
			strcpy(newone->Genre,temp->Genre);

			Insert_Node(ins,newone);
			newone=NULL;
			count++;
		}

		temp = temp -> Rlink;
	}

	printf("\nWe found %d songs that match the Album.\n\n",count);
	printf("***************************************************[Songs]***************************************************\n");
	printf("*%-20s %-24s %-4s %-31s %-s %-13s*\n",tab_artist,tab_title,tab_time,tab_album,tab_track_num,tab_Genre);

	if(count == 0)
	{
		printf("*                                                                                                           *\n");
		printf("*                                            No Matched Album :(                                            *\n");
		printf("*                                                                                                           *\n");
		printf("*************************************************************************************************************\n");
		re=false;
		system("pause");
	}
	else if(count == 1) Print_Node(newhead->Rlink);
	else Print_List(newhead,newhead->Rlink,newhead);
	if(re){
		// newnode에 검색 결과가 저장
		printf("*************************************************************************************************************\n");
		do{
			printf("*                 1. Play the Song         2. Add to Playlist            3. Quit                        *\n");
			printf("*************************************************************************************************************\n");
			printf("#input :"); 
BSEARCH:		
			scanf("%d",&bsearch_input);
			switch(bsearch_input){
			case 1: //Play song
				checkk=false;
				system("cls");
				Player_Function(newhead);
				break;

			case 2: //Add to playlist
				checkk=false;
				system("cls");
				Add_to_Playlist(newhead);
				break;

			case 3:
				checkk=false;
				system("cls");
				break;

			default:
				printf("Wrong Number! Please Input Again :");
				goto BSEARCH;
			}
		}while(checkk);
	}
	else{
					
	}
	system("cls");	

}
void ShowSongs_Search_Genre(list_ptr head) //////
{
	char tab_artist[9]="<Artist>";
	char tab_title[8]="<Title>";
	char tab_time[7]="<Time>";
	char tab_album[8]="<Album>";
	char tab_track_num[9]="<#Track>";
	char tab_Genre[8]="<Genre>";
	char genre_serach[20];
	int count = 0,gsearch_input,checkk=true,re=true;
	list_ptr temp = NULL;
	list_ptr newone = NULL;
	list_ptr newhead = NULL;
	list_ptr ins = NULL;

	newhead=(list_ptr)malloc(sizeof(list_node));
	newhead->Rlink=newhead;
	newhead->Llink=newhead;

	temp = head->Rlink;

	printf("* Please Replace ' '(Space) to '_'.\n");
	printf("Enter the Genre : ");
	scanf("%s", genre_serach);

	ins = newhead;

	while(temp != head)
	{
		if(!strcmp(temp->Genre,genre_serach))
		{
			newone=(list_ptr)malloc(sizeof(list_node));

			strcpy(newone->artist,temp->artist);
			strcpy(newone->title,temp->title);
			strcpy(newone->time,temp->time);
			strcpy(newone->album,temp->album);
			newone->track_num = temp->track_num;
			strcpy(newone->Genre,temp->Genre);

			Insert_Node(ins,newone);
			newone=NULL;
			count++;
		}

		temp = temp -> Rlink;
	}

	printf("\nWe found %d songs that match the Genre.\n\n",count);
	printf("***************************************************[Songs]***************************************************\n");
	printf("*%-20s %-24s %-4s %-31s %-s %-13s*\n",tab_artist,tab_title,tab_time,tab_album,tab_track_num,tab_Genre);

	if(count == 0)
	{
		printf("*                                                                                                           *\n");
		printf("*                                            No Matched Genre :(                                            *\n");
		printf("*                                                                                                           *\n");
		printf("*************************************************************************************************************\n");
		re=false;
		system("pause");
	}
	else if(count == 1) Print_Node(newhead->Rlink);
	else Print_List(newhead,newhead->Rlink,newhead);
	printf("*************************************************************************************************************\n\n");
	
	if(re){
		// newnode에 검색 결과가 저장
		printf("*************************************************************************************************************\n");
		do{
			printf("*                 1. Play the Song         2. Add to Playlist            3. Quit                        *\n");
			printf("*************************************************************************************************************\n");
			printf("#input :"); 
GSEARCH:		
			scanf("%d",&gsearch_input);
			switch(gsearch_input){
			case 1: //Play song
				checkk=false;
				system("cls");
				Player_Function(newhead);
				break;
			case 2: //Add to playlist
				checkk=false;
				system("cls");
				Add_to_Playlist(newhead);
				break;
			case 3:
				checkk=false;
				system("cls");
				break;
			default:
				printf("Wrong Number! Please Input Again :");
				goto GSEARCH;
			}
		}while(checkk);
	}
	else{
				
	}
	system("cls");
}


/////<유저인터페이스>///////////////////////////////////////////////////////////////
void ShowSongs()	//1번
{
	int user_input1;
	int checkq=true;
	int check_sort[4]={0,0,0,0};

	char tab_artist[9]="<Artist>";
	char tab_title[8]="<Title>";
	char tab_time[7]="<Time>";
	char tab_album[8]="<Album>";
	char tab_track_num[9]="<#Track>";
	char tab_Genre[8]="<Genre>";


	do{
		printf("***************************************************[Songs]***************************************************\n");
		printf("*%-20s %-24s %-4s %-31s %-s %-13s*\n",tab_artist,tab_title,tab_time,tab_album,tab_track_num,tab_Genre);
		//출력
		Print_List(main_head,main_head->Rlink,main_head);

		printf("**************************************************[Tab Menu]*************************************************\n");
		printf("                       1.Play Songs            2.Sort By Title          3.Sort By Artist\n");
		printf("                       4.Sort By Album         5.Sort By Genre          6.Go to Upper Menu\n");
		printf("*************************************************************************************************************\n");

		printf("                                                    #Input :");
AGAIN1:
		scanf("%d",&user_input1);

		switch(user_input1){
		case 1:
			system("cls");
			ShowSongs_PlaySongs();
			break;
		case 2:
			check_sort[1] = check_sort[2] = check_sort[3] = 0;
			system("cls");
			ShowSongs_Sort_Title(check_sort[TITLE]++);
			break;
		case 3:
			check_sort[0] = check_sort[2] = check_sort[3] = 0;
			system("cls");
			ShowSongs_Sort_Artist(check_sort[ARTIST]++);
			break;
		case 4:
			check_sort[0] = check_sort[1] = check_sort[3] = 0;
			system("cls");
			ShowSongs_Sort_Album(check_sort[ALBUM]++);
			break;
		case 5:
			check_sort[0] = check_sort[1] = check_sort[2] = 0;
			system("cls");
			ShowSongs_Sort_Genre(check_sort[GENRE]++);
			break;
		case 6:
			system("cls");
			checkq=false;
			break;
		default:
			printf("                                           Wrong Number! Please Try Again.\n");
			printf("                                                    #Input :");
			goto AGAIN1;
		}
	}while(checkq);

}
void SearchSongs(list_ptr head)	//2번
{
	list_ptr temp=NULL;
	int user_input1;
	int checkq=true;
	
	do{
	printf("**********************************************[Search Criteria]**********************************************\n");
	printf("                              1.Artist           2.Title           3.Album\n");
	printf("                              4.Genre            5.Go to Upper Menu\n");
	printf("*************************************************************************************************************\n");
	printf("                                                    #Input :");
	
	AGAIN1:
		scanf("%d",&user_input1);

		switch(user_input1){
		case 1:
			system("cls");
			ShowSongs_Search_Artist(head);
			break;
		case 2:
			system("cls");
			ShowSongs_Search_Title(head);
			break;
		case 3:
			system("cls");
			ShowSongs_Search_Album(head);
			break;
		case 4:
			system("cls");
			ShowSongs_Search_Genre(head);
			break;
		case 5:
			system("cls");
			checkq=false;
			break;
		default:
			printf("                                           Wrong Number! Please Try Again.\n");
			printf("                                                    #Input :");
			goto AGAIN1;
		}
	}while(checkq);

	
}
void ShowPlayLists()	//3번
{
	int showplaylists_input,checkk,isempty=true;
	char test=true, intention;

	if(plist_head->Rlink==plist_head){
		test=false;
		isempty=false;
	}

	while(test){
		if(plist_head->Rlink!=plist_head){
			printf("***************************************************[Playlist]***************************************************\n");
			Print_pList(plist_head,plist_head->Rlink,plist_head);
			printf("****************************************************************************************************************\n");
			printf("     1.Make a new playlist.        2.Choose Playlist        3.Delete Playlist       4.Go to Upper Menu\n");
			printf("****************************************************************************************************************\n");
			printf("#input :");

SHOWPLAYLISTS_AGAIN:
			scanf("%d",&showplaylists_input);

			switch(showplaylists_input){
			case 1:
				system("cls");
				Make_Playlist();
				break;
			case 2:
				system("cls");
				ShowPlayLists_Choose_Playlist();
				break;
			case 3:
				//system("cls");
				ShowPlayLists_Delete_Playlist();
				break;
			case 4:
				test=false;
				system("cls");
				break;
			default:
				printf("Wrong Number! Please Input Again :");
				goto SHOWPLAYLISTS_AGAIN;
			}
		}
		else{
			printf("There is no Playlist. Would you like to make new one? (y/n):");
			scanf("%c",&test);
			if(test=='y'){
				test=true;
				system("cls");
				Make_Playlist();
			}
			else{
				test=false;			
				system("cls");
			}
		}
	}
	if(!isempty){
		
		printf("Oops! There is no playlist :(\n");
		printf("Would you like to make a new list? (y/n):");
INPUTLETTER_AGAIN:	
		fflush(stdin);
		scanf("%c",&intention);
		
		if(intention=='n'){
			printf("You Canceled.\n");
			fflush(stdin);
			system("pause");
			system("cls");			
		}
		else if(intention=='y')
			Make_Playlist();
		else{
			printf("I think it's Wrong Letter. Please Try Again (y/n):");
			goto INPUTLETTER_AGAIN;
		}
	}
}
void AddSong(list_ptr start)
{
	list_ptr addone=NULL;
	char test;
	addone=(list_ptr)malloc(sizeof(list_node));
	addone->Rlink=NULL;
	addone->Llink=NULL;

	printf("*******************************************[Add New Song]*******************************************\n");
	printf("!! Please Replace ' '(Space) to '_'(Underbar). :)\n");
	printf("Artist:");
	scanf("%s",addone->artist);
	fflush(stdin);
	printf("Title:");
	scanf("%s",addone->title);
	fflush(stdin);
	printf("Time:");
	scanf("%s",addone->time);
	fflush(stdin);
	printf("Album:");
	scanf("%s",addone->album);
	fflush(stdin);
	printf("Track Number:");
	scanf("%d",&addone->track_num);
	fflush(stdin);
	printf("Genre:");
	scanf("%s",addone->Genre);	
	fflush(stdin);
	printf("                                 ***********************************\n");
	printf("                                 *      Artist: %s\n",addone->artist);
	printf("                                 *      Artist: %s\n",addone->title);
	printf("                                 *      Artist: %s\n",addone->time);
	printf("                                 *      Artist: %s\n",addone->album);
	printf("                                 *      Artist: %d\n",addone->track_num);
	printf("                                 *      Artist: %s\n",addone->Genre);
	printf("                                 ***********************************\n");
	printf("Are You Sure? (y/n):");

ADDSONG_AGAIN:
	scanf("%c",&test);
	fflush(stdin);

	if(test=='n'){
		printf("You Canceled Addition.\n");
		system("pause");
		system("cls");
	}
	else if(test=='y'){
		Insert_Node(main_head->Llink, addone);
		num_total_songs++;
		
		printf("Successfully Added!\n");
		system("pause");
		system("cls");
		}
	else{
		printf("Wrong Character! Please Input Correctly :");
		goto ADDSONG_AGAIN;
	}
}