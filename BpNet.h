// BpNet.h: interface for the BpNet class.
// 2005.1.13��16��02 By Superman 
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BPNET_H__3A171E41_1E8B_11D7_BA67_936006E9954B__INCLUDED_)
#define AFX_BPNET_H__3A171E41_1E8B_11D7_BA67_936006E9954B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define SAMPLE_NUM 200

#define MAX_IN_NUM 200
#define MAX_HIDE_NUM 300
#define MAX_OUT_NUM 20

class BpNet  
{
public:
	double tjpt[MAX_OUT_NUM];
	double shuchu[MAX_OUT_NUM];
	double m[MAX_OUT_NUM];
	double * sim(double *psim);
	void train(double p[][MAX_IN_NUM],double t[][MAX_OUT_NUM],int samplenum);

	BpNet(int argIn,int argHide,int argOut);

	virtual ~BpNet();

	int inNum;  //��������
	int hideNum;//���������
	int outNum;  //��������

	double x[SAMPLE_NUM]; //��������
	double x1[SAMPLE_NUM];//�������״ֵ̬
	double x2[SAMPLE_NUM];//������״ֵ̬
	double o1[SAMPLE_NUM];//�����㼤��ֵ
	double o2[SAMPLE_NUM];//����㼤��ֵ
	double w[MAX_IN_NUM][MAX_HIDE_NUM];//�������Ȩֵ
	double w1[MAX_HIDE_NUM][MAX_OUT_NUM];//������Ȩֵ
	double rate_w; //Ȩֵѧϰ�ʣ������-������)
	double rate_w1;//Ȩֵѧϰ�� (������-�����)
	double rate_b1;//�����㷧ֵѧϰ��
	double rate_b2;//����㷧ֵѧϰ��
	double b1[MAX_HIDE_NUM];//������㷧ֵ
	double b2[MAX_OUT_NUM];//�����㷧ֵ
	double pp[SAMPLE_NUM];
	double qq[SAMPLE_NUM];
	double yd[SAMPLE_NUM];//ϣ�����ֵ
	double e;
	double error;//�����������
public:
	void SaveToFile(CString str);
public:
	void LoadFromFile(CString str);
};

#endif // !defined(AFX_BPNET_H__3A171E41_1E8B_11D7_BA67_936006E9954B__INCLUDED_)
