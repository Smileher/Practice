/*****************
 *�༶��16��ת��
 *�������º�
 *ѧ�ţ�20160566140
 *C����ʵ����
 *****************/
#include <stdio.h>
#include <string.h>
#define SN 2//ѧ����
#define N 5//�γ���
//����γ̽ṹ�����͡��γ̺š��γ������ɼ���
typedef struct CLASS
{
    int number;
    char name[32];
    double score;
}CLASS;
//����ѧ���ṹ�����͡�ѧ�š�������5�ſγ̡�
typedef struct STU
{
    int number[32];
    char name[32];
    CLASS class[N];
}STU;
//����ѧ����Ϣ���뺯�����ֱ���������ѧ����Ϣ
void input(STU student[SN])
{
    int i,j;
    printf("***************��ӭʹ�óɼ�����ϵͳ(By�º�)*****************\n");
    printf("��ֱ�������%d�ſεĿγ���Ϣ(�γ̺źͿγ���,�ÿո����)\n",N);
    
    for(j=0;j<N;j++)
    {
    	printf("��%d�ſ�:",j+1);
    	scanf("%d %s",&student[0].class[j].number,student[0].class[j].name);
    	for(i=0;i<SN;i++)
    	{
			student[i+1].class[j].number=student[i].class[j].number;
			strncpy(student[i+1].class[j].name,student[i].class[j].name,32);
		}
	   		//while(getchar()=='\n'); 
	}
	
	printf("\n��ֱ�������%dλѧ������Ϣ(ѧ�ź��������ÿո����)\n",SN);
    for(i=0;i<SN;i++)
    {
        printf("��%dλѧ��:",i+1);
        scanf("%d %s",&student[i].number,student[i].name);
        for(j=0;j<N;j++)
        {
            printf("%s��%s�εĳɼ�:",student[i].name,student[i].class[j].name);
            scanf("%lf",&student[i].class[j].score);
        }
    }
    
}
//������ÿ��ѧ�����ܳɼ�����
void score(STU student[SN],double scoreALL[SN])
{
    int i,j;
    //scoreALL[SN] = {0.0};
    for(i=0;i<SN;i++)
    {
        for(j=0;j<N;j++)
        {
            scoreALL[i]=student[i].class[j].score;
        }
    }
}
//������ÿ�ſγ�ƽ���ɼ�������ѧ��ƽ���ɼ�
void average(STU student[SN],double averageCLASS[N],double averageSTU[SN],double scoreALL[SN])
{
    int i,j;
    //averageCLASS[N]={0.0};
    //averageSTU[SN]={0.0};
    for(i=0;i<SN;i++)
    {
        averageSTU[i]=scoreALL[i]/SN;
    }
    for(j=0;j<N;j++)
    {
        for(i=0;i<SN;i++)
        {
            averageCLASS[j]=student[i].class[j].score;
        }
    }
}
int main(void)
{
    int i,j;
    STU student[SN];//����ѧ������洢
    double scoreALL[SN]={0.0};//ÿ��ѧ�����ܳɼ�
    double averageCLASS[N]={0.0};//ÿ�ſγ�ƽ���ɼ�
    double averageSTU[SN]={0.0};//ѧ��ƽ���ɼ�
    input(student);
    score(student,scoreALL);
    average(student,averageCLASS,averageSTU,scoreALL);
    printf("\nһ����%d��ѧ��:\n",SN);
    for(i=0;i<SN;i++)
    {
    	printf("****************************************\nѧ��:%s\n",student[i].name);
        for(j=0;j<N;j++)
        {
            printf("%s�εĳɼ���%.2lf:\n",student[i].class[j].name,student[i].class[j].score);
        }
        printf("�ܳɼ���:%.2lf,ƽ���ɼ���:%.2lf\n\n",scoreALL[i],averageSTU[i]);
    }
    printf("\nһ����%d�ſ�:\n",N);
    for(j=0;j<N;j++)
    {
    	printf("%s���ſ������˵�ƽ���ɼ���:%.2lf\n",student[0].class[j].name,averageCLASS[j]);
	}
    return 0;
}
