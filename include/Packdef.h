#ifndef _PACKDEF_H
#define _PACKDEF_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <sys/epoll.h>
#include <sys/stat.h>
#include <pthread.h>
#include <signal.h>
#include <errno.h>
#include "err_str.h"
#include <malloc.h>

#include "Queue.h"
//�߽�ֵ
#define _DEF_SIZE 45
#define _DEF_BUFFERSIZE 1000
#define _DEF_PORT 8000
#define _DEF_SERVERIP "192.168.0.104"

enum{
	fitness = 1,
	entertainment,
	food,
	beautifulgirl,
	view
};
#define _DEF_LISTEN 128
#define _DEF_EPOLLSIZE 4096
#define _DEF_IPSIZE 16
#define _DEF_COUNT 10
#define _DEF_TIMEOUT 10
#define _DEF_SQLIEN 400




pthread_mutex_t alock;
pthread_mutex_t rlock;

#define _DEF_PROTOCOL_BASE 100
////1.ע��
//#define _DEF_PROTOCOL_REGISTER_RQ _DEF_PROTOCOL_BASE +1
//#define _DEF_PROTOCOL_REGISTER_RS _DEF_PROTOCOL_BASE +2
////2.��¼
//#define _DEF_PROTOCOL_LOGIN_RQ _DEF_PROTOCOL_BASE +3
//#define _DEF_PROTOCOL_LOGIN_RS _DEF_PROTOCOL_BASE +4
////3.�༭������Ϣ
//#define _DEF_PROTOCOL_EDITPERSONINFO_RQ _DEF_PROTOCOL_BASE +5
//#define _DEF_PROTOCOL_EDITPERSONINFO_RS _DEF_PROTOCOL_BASE +6
////4.��ȡ���߽ṹ����Ϣ
//#define _DEF_PROTOCOL_GETAUTHORINFO_RQ _DEF_PROTOCOL_BASE +7
//#define _DEF_PROTOCOL_GETAUTHORINFO_RS _DEF_PROTOCOL_BASE +8
////5.��ȡ������Ƶ����ͷ
//#define _DEF_PROTOCOL_GETAUTHORVIDEOSTREAMHEAD_RQ _DEF_PROTOCOL_BASE +9
//#define _DEF_PROTOCOL_GETAUTHORVIDEOSTREAMHEAD_RS _DEF_PROTOCOL_BASE +10
////6.��ȡ������Ƶ����
//#define _DEF_PROTOCOL_GETAUTHORVIDEOSTREAM_RQ _DEF_PROTOCOL_BASE +11
//#define _DEF_PROTOCOL_GETAUTHORVIDEOSTREAM_RS _DEF_PROTOCOL_BASE +12
////7.�ϴ���Ƶ����ͷ
//#define _DEF_PROTOCOL_UPLOADVIDEOHEAD_RQ _DEF_PROTOCOL_BASE +13
//#define _DEF_PROTOCOL_UPLOADVIDEOHEAD_RS _DEF_PROTOCOL_BASE +14
////8.�ϴ���Ƶ��
//#define _DEF_PROTOCOL_UPLOADVIDEOSTREAM_RQ _DEF_PROTOCOL_BASE +15
//#define _DEF_PROTOCOL_UPLOADVIDEOSTREAM_RS _DEF_PROTOCOL_BASE +16
////9.����
//#define _DEF_PROTOCOL_GIVENIDEOEVALUATE_RQ _DEF_PROTOCOL_BASE +17
//#define _DEF_PROTOCOL_GIVENIDEOEVALUATE_RS _DEF_PROTOCOL_BASE +18
////10.�˳�
//#define _DEF_PROTOCOL_QUITAUTHOR_RQ   _DEF_PROTOCOL_BASE +19
//#define _DEF_PROTOCOL_QUITAUTHOR_RS   _DEF_PROTOCOL_BASE +20
//
//
//
////m_lResult�ظ�״̬
////ע��״̬
//#define _register_fail 0
//#define _register_success 1
////��¼״̬
//#define _login_noexist 0
//#define _login_password_err 1
//#define _login_success 2
////���ø�����Ϣ״̬
//#define _EDITPERSONINFO_fail 0
//#define _EDITPERSONINFO_success 1
////��ȡ�Լ���������Ϣ״̬
//#define _GETAUTHORINFO_fail 0
//#define _GETAUTHORINFO_success 1
////����״̬
//#define _GIVENIDEOEVALUATE_fail 0
//#define _GIVENIDEOEVALUATE_success 1
////�˳�״̬
//#define _QUITAUTHOR_fail 0
//#define _QUITAUTHOR_success 1
//
//
//
#define TRUE 1
#define FALSE 0
//
//
//enum Sex{sex_male,sex_female};
//
////Э���
//typedef char PackType;
//
//
////��¼orע�������
//typedef struct
//{
//	PackType  m_nType;
//	long long m_userid;
//	char	  m_username[_DEF_SIZE];
//	char      m_szPassword[_DEF_SIZE];
//
//}STRU_LOGIN_RQ,STRU_REGISTER_RQ;
////��¼orע��ظ���
//#pragma pack(4)
//typedef struct
//{
//	PackType   m_nType;
//	long long  m_userid;
//	char       m_lResult;    //���ؽ��
//}STRU_LOGIN_RS,STRU_REGISTER_RS;
//
//
//
////���ø�����Ϣ�����
//struct STRU_EDITPERSONINFO_RQ
//{
//	PackType   m_nType;
//	long long  m_userid;      //�û�ID
//	char       m_szName[_DEF_SIZE];//�ǳ�
//	char       m_szSignature [_DEF_SIZE];//ǩ��
//	enum Sex 	   sex;              //�Ա�
//};
////���ø�����Ϣ�ظ���
//typedef struct
//{
//	PackType   m_nType;
//	long long  m_userid;      //�û�ID
//	char       m_lResult;    //���ؽ��
//}STRU_EDITPERSONINFO_RS;
//
////��ȡ�Լ���������Ϣ�����
//typedef struct
//{
//	PackType   m_nType;
//	char m_username[_DEF_SIZE];
//}STRU_GETAUTHORINFO_RQ;
////��ȡ�Լ���������Ϣ�ظ���
//typedef struct
//{
//	PackType   m_nType;
//	char       m_username[_DEF_SIZE];
//	char	   szbuf[_DEF_BUFFERSIZE];
//	int 	   nNum_praise;  //��������
//}STRU_GETAUTHORINFO_RS;
//
////��Ƶ��Ϣ
//typedef struct STRU_VIDEOInfo
//{
//	int nNum_praise;
//	char m_videoname[_DEF_SIZE];
//	char m_username[_DEF_SIZE];
//	int videotype;
//}STRU_VIDEOINFO;
//
////��ȡ��Ƶ����ͷor��Ƶ�������
//typedef struct
//{
//	PackType   m_nType;
//	char m_username[_DEF_SIZE];
//}STRU_GETAUTHORVIDEOSTREAM_RQ,STRU_GETAUTHORVIDEOSTREAMHEAD_RQ;
////��ȡ��Ƶ����ͷor��Ƶ���ظ���
//typedef struct
//{
//	PackType   m_nType;
//	long long n_len;   //��Ƶ����С
//	STRU_VIDEOINFO su_videoinfo;
//}STRU_GETAUTHORVIDEOSTREAMHEAD_RS;
//
//typedef struct
//{
//	PackType   m_nType;
//	char szbuf[_DEF_BUFFERSIZE];    //װ��Ƶ��������Ƶ����Ϣ
//	long long n_len;   //��Ƶ����С
//}STRU_GETAUTHORVIDEOSTREAM_RS;
//
////�ϴ���Ƶ������
//#pragma pack(4)
//typedef struct NODE_1
//{
//	PackType   m_nType;
//	STRU_VIDEOINFO su_videoinfo;
//	long long n_len;   //��Ƶ����С
//}STRU_UPLOADVIDEOHEAD_RQ;
//#pragma pack(4)
//typedef struct NODE_2
//{
//	PackType   m_nType;
//	char szbuf[_DEF_BUFFERSIZE];
//	long long n_len;   //��Ƶ����С
//}STRU_UPLOADVIDEOSTREAM_RQ;
////�ϴ���Ƶ���ظ���
//typedef struct STRU_UPLOADVIDEOHEAD_RS
//{
//	PackType   m_nType;
//}STRU_UPLOADVIDEOSTREAM_RS;
//
//
////���������
//typedef struct STRU_GIVENIDEOEVALUATE_Rq
//{
//	PackType   m_nType;
//	STRU_VIDEOINFO su_videoinfo;   //���޶���
//}STRU_GIVENIDEOEVALUATE_RQ;
////���޻ظ���
//typedef struct STRU_GIVENIDEOEVALUATE_Rs
//{
//	PackType   m_nType;
//	char       m_lResult;    //���ؽ��
//}STRU_GIVENIDEOEVALUATE_RS;
//
//
////�˳���¼�����
//typedef struct STRU_QUITAUTHOR_Rq
//{
//	PackType  m_nType;
//	long long m_userid;
//}STRU_QUITAUTHOR_RQ;
////�˳���¼�ظ���
//typedef struct STRU_QUITAUTHOR_Rs
//{
//	PackType  m_nType;
//	long long m_userid;
//	char      m_lResult;    //���ؽ��
//}STRU_qUITAUTHOR_RS;

#define BOOL bool
#define DEF_PACK_BASE  (10000)
//ע��
#define  DEF_PACK_REGISTER_RQ    (DEF_PACK_BASE + 0)
#define  DEF_PACK_REGISTER_RS    (DEF_PACK_BASE + 1)

//��¼
#define  DEF_PACK_LOGIN_RQ    (DEF_PACK_BASE + 2)
#define  DEF_PACK_LOGIN_RS    (DEF_PACK_BASE + 3)

//�ϴ�
#define DEF_PACK_UPLOAD_RQ    (DEF_PACK_BASE + 4)
#define DEF_PACK_UPLOAD_RS    (DEF_PACK_BASE + 5)

//�ϴ��ļ���
#define DEF_PACK_UPLOAD_FILEBLOCK_RQ    (DEF_PACK_BASE + 6)
#define DEF_PACK_UPLOAD_FILEBLOCK_RS    (DEF_PACK_BASE + 7)

//����
#define DEF_PACK_DOWNLOAD_RQ    (DEF_PACK_BASE + 8)
#define DEF_PACK_DOWNLOAD_RS    (DEF_PACK_BASE + 9)

//�����ļ���
#define DEF_PACK_DOWNLOAD_FILEBLOCK_RQ    (DEF_PACK_BASE + 10)
#define DEF_PACK_DOWNLOAD_FILEBLOCK_RS    (DEF_PACK_BASE + 11)

//�ύ������
#define DEF_PACK_PRESSLIKE_RQ  (DEF_PACK_BASE + 12)


//ע��������
#define userid_is_exist      0
#define register_sucess      1

//��¼������
#define userid_no_exist      0
#define password_error       1
#define login_sucess         2

//�ϴ�������
#define file_is_exist        0
#define file_uploaded        1
#define file_uploadrq_sucess 2
#define file_upload_refuse   3

//�ϴ��ظ����
#define fileblock_failed     0
#define fileblock_success    1

//����������
#define file_downrq_failed   0
#define file_downrq_success  1

#define _downloadfileblock_fail  0
#define _downloadfileblock_success	1

#define DEF_PACK_COUNT (100)

#define MAX_PATH            (280 )
#define MAX_SIZE            (60  )
#define DEF_HOBBY_COUNT     (8  )
#define MAX_CONTENT_LEN     (4096 )


/////////////////////����//////////////////////////////////////
#define DEF_TCP_PORT   8000

#define DEF_MAX_BUF	  1024
#define DEF_BUFF_SIZE	  4096


typedef int PackType;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//��¼����
typedef struct STRU_LOGIN_RQ
{
//    STRU_LOGIN_RQ()
//    {
//        m_nType = DEF_PACK_LOGIN_RQ;
//        memset(m_szUser,0,MAX_SIZE);
//        memset(m_szPassword,0,MAX_SIZE);
//    }

    PackType m_nType;   //������
    char     m_szUser[MAX_SIZE] ; //�û�ID
    char     m_szPassword[MAX_SIZE];  //����
}STRU_LOGIN_RQ;


//��¼�ظ�
typedef struct STRU_LOGIN_RS
{
//    STRU_LOGIN_RS()
//    {
//        m_nType= DEF_PACK_LOGIN_RS;
//    }
    PackType m_nType;   //������
    int  m_UserID;
    int  m_lResult ; //ע����

}STRU_LOGIN_RS;


//ע������
typedef struct STRU_REGISTER_RQ
{
//    STRU_REGISTER_RQ()
//    {
//        m_nType = DEF_PACK_REGISTER_RQ;
//        memset(m_szUser,0,MAX_SIZE);
//        memset(m_szPassword,0,MAX_SIZE);
//    }

    PackType m_nType;   //������
    char     m_szUser[MAX_SIZE] ; //�û�ID
    char     m_szPassword[MAX_SIZE];  //����
    int    food;
    int    funny;
    int    ennegy;
    int    dance;
    int    music;
    int    video;
    int    outside;
    int    edu;
}STRU_REGISTER_RQ;

//ע��ظ�
typedef struct STRU_REGISTER_RS
{
//    STRU_REGISTER_RS()
//    {
//        m_nType= DEF_PACK_REGISTER_RS;
//    }
    PackType m_nType;   //������
    int  m_lResult ; //ע����

}STRU_REGISTER_RS;


//�����ļ�����

typedef struct STRU_DOWNLOAD_RQ
{
//    STRU_DOWNLOAD_RQ()
//    {
//        m_nType = DEF_PACK_DOWNLOAD_RQ;
//        m_nUserId = 0;
//    }
    PackType   m_nType;   //������
    int    m_nUserId; //�û�ID

}STRU_DOWNLOAD_RQ;

//�����ļ��ظ�
typedef struct STRU_DOWNLOAD_RS
{
//    STRU_DOWNLOAD_RS()
//    {
//        m_nType = DEF_PACK_DOWNLOAD_RS;
//        m_nFileId = 0;
//        memset(m_szFileName , 0 ,MAX_PATH);
//        memset(m_rtmp , 0 ,MAX_PATH);
//    }
    PackType m_nType;   //������
    int      m_nFileId;
    int64_t  m_nFileSize;
    int      m_nVideoId;
    char     m_szFileName[MAX_PATH];
    char     m_rtmp[MAX_PATH];

}STRU_DOWNLOAD_RS;

//�ļ�������

typedef struct STRU_DOWNLOAD_FILEBLOCK_RQ
{
//    STRU_DOWNLOAD_FILEBLOCK_RQ()
//    {
//        m_nType = DEF_PACK_DOWNLOAD_FILEBLOCK_RQ;
//        m_nUserId = 0;
//        m_nFileId =0;
//        m_nBlockLen =0;
//        m_nBlockId = 0;
//        ZeroMemory(m_szFileContent,MAX_CONTENT_LEN);
//    }
    PackType m_nType;   //������
    int    m_nUserId; //�û�ID
    int    m_nFileId;
    int    m_nBlockLen;
    char     m_szFileContent[MAX_CONTENT_LEN];
}STRU_DOWNLOAD_FILEBLOCK_RQ;


//�ļ���ظ���
typedef struct STRU_DOWNLOAD_FILEBLOCK_RS
{
//    STRU_DOWNLOAD_FILEBLOCK_RS()
//    {
//        m_nType = DEF_PACK_DOWNLOAD_FILEBLOCK_RS;
//        m_nUserId = 0;
//        m_nFileId =0;
//        m_nBlockLen =0;
//        m_nResult = 0;
//    }
    PackType m_nType;   //������
    int    m_nUserId; //�û�ID
    int    m_nFileId;
    int     m_nResult;
    int64_t    m_nBlockLen;
}STRU_DOWNLOAD_FILEBLOCK_RS;

//�ϴ��ļ�����
typedef struct STRU_UPLOAD_RQ
{
//    STRU_UPLOAD_RQ()
//    {
//        m_nType = DEF_PACK_UPLOAD_RQ;
//        m_nFileId = 0;
//        m_UserId = 0;
//        m_nVideoId = 0;
//        memset(m_szFileName , 0 ,MAX_PATH);
//    }
    PackType m_nType;   //������
    int      m_UserId;
    int      m_nFileId;
    int      m_nVideoId;
    int64_t  m_nFileSize;
    char     m_szHobby[DEF_HOBBY_COUNT];
    char     m_szFileName[MAX_PATH];
    char     m_szFileType[MAX_SIZE];

}STRU_UPLOAD_RQ;

//�ϴ��ļ��ɹ��ظ�
typedef struct STRU_UPLOAD_RS
{
//    STRU_UPLOAD_RS()
//    {
//        m_nType = DEF_PACK_UPLOAD_RS;
//        m_nResult = 0;
//    }
    PackType m_nType;   //������
    int      m_nResult;

}STRU_UPLOAD_RS;

//�ϴ��ļ�������
typedef struct STRU_UPLOAD_FILEBLOCK_RQ
{
//    STRU_UPLOAD_FILEBLOCK_RQ()
//    {
//        m_nType = DEF_PACK_UPLOAD_FILEBLOCK_RQ;
//        m_nUserId = 0;
//        m_nFileId =0;
//        m_nVideoId = 0;
//        m_nBlockLen =0;
//        ZeroMemory(m_szFileContent,MAX_CONTENT_LEN);
//    }
    PackType m_nType;   //������
    int    m_nUserId; //�û�ID
    int    m_nFileId;
    int    m_nVideoId;
    int    m_nBlockLen;
    char   m_szFileContent[MAX_CONTENT_LEN];

}STRU_UPLOAD_FILEBLOCK_RQ;

//��Ƶ����
typedef struct STRU_PRESSLIKE_RQ
{

    PackType m_nType;   //������
    int    m_nUserId; //�û�ID
    int    m_nVideoId;

}STRU_PRESSLIKE_RQ;

typedef struct STRU_FILEINFO
{
    int m_nFileID;//���d�ĕr�����Á���UI�ؼ���̖�ģ� �ς��ĕr����һ���S�C���� �^���ļ���
    int m_VideoID;//�����ļ�ID �cMysql��һ��
    int64_t m_nFileSize;
    int64_t m_nPos;
    int m_nUserId;
    FILE* pFile;
    char m_szFilePath[MAX_PATH];
    char m_szFileName[MAX_PATH];
    char m_szFileType[MAX_SIZE];
    char m_Hobby[DEF_HOBBY_COUNT];
    char m_UserName[MAX_SIZE];
    char m_szRtmp[MAX_PATH];

}FileInfo;


#endif



