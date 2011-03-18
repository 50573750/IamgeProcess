// BpNet.cpp: implementation of the BpNet class.
// 2005.1.13��16��02 By Superman 
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "BpNet.h"
#include "math.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

BpNet::BpNet(int argIn,int argHide,int argOut)
{ 
	inNum = argIn;
	hideNum = argHide;
	outNum = argOut;

	srand(time(NULL));

	for(int i=0;i<MAX_OUT_NUM;i++)
	{
		tjpt[i] = 0;
	}

	for(int i=0;i<inNum;i++)
	{
		for(int j=0;j<hideNum;j++)
		{
			int r = rand()%20000 - 10000;
			double dCur = float(r)/10000;
			w[i][j] = dCur;
		}
	}

	for(int i=0;i<hideNum;i++)
	{
		for(int j=0;j<outNum;j++)
		{
			int r = rand()%20000 - 10000;
			double dCur = float(r)/10000;
			w1[i][j] = dCur;
		}
	}

	for(int i=0;i<hideNum;i++)
	{
		int r = rand()%20000 - 10000;
		double dCur = float(r)/10000;

		b1[i] = dCur;
	}

	for(int i=0;i<outNum;i++)
	{
		int r = rand()%20000 - 10000;
		double dCur = float(r)/10000;

		b2[i] = dCur;
	}

	for(int i=0;i<SAMPLE_NUM;i++)
	{
		x[i]=0;
		x1[i]=0;
		x2[i]=0;
		o1[i]=0;
		o2[i]=0;
		pp[i]=0;
		qq[i]=0;
		yd[i]=0.0;
	}
	error=0.001;
	e=0.0;

	rate_w=0.05;  //Ȩֵѧϰ�ʣ������--������)
	rate_w1=0.047; //Ȩֵѧϰ�� (������--�����)
	rate_b1=0.05; //�����㷧ֵѧϰ��
	rate_b2=0.047; //����㷧ֵѧϰ��
}

BpNet::~BpNet()
{

}

void BpNet::train(double p[][MAX_IN_NUM],double t[][MAX_OUT_NUM],int samplenum)
{
	for(int isamp=0;isamp<samplenum;isamp++)//ѭ��ѵ��һ����Ʒ
	{ 
		for(int i=0;i<inNum;i++)
			x[i]=p[isamp][i];		
		for(int i=0;i<outNum;i++)
			yd[i]=t[isamp][i];

		//����ÿ����Ʒ������������׼
		for(int j=0;j<hideNum;j++)
		{
			o1[j]=0.0;

			for(int i=0;i<inNum;i++)
				o1[j]=o1[j]+w[i][j]*x[i];//���������Ԫ���뼤��ֵ
			x1[j]=1.0/(1+exp(-o1[j]-b1[j]));//���������Ԫ�����
		}

		for(int k=0;k<outNum;k++)
		{
			o2[k]=0.0;

			for(int j=0;j<hideNum;j++)
				o2[k]=o2[k]+w1[j][k]*x1[j];//��������Ԫ���뼤��ֵ
			x2[k]=1.0/(1.0+exp(-o2[k]-b2[k]));//��������Ԫ���
		}

		for(int k=0;k<outNum;k++)
		{
			e=0.0;
			qq[k]=(yd[k]-x2[k])*x2[k]*(1.-x2[k]);//ϣ�������ʵ�������ƫ��
			e+=fabs(yd[k]-x2[k])*fabs(yd[k]-x2[k]);//���������

			for(int j=0;j<hideNum;j++)
				w1[j][k]=w1[j][k]+rate_w1*qq[k]*x1[j];//��һ�ε�������������֮���������Ȩ
			e=sqrt(e);
			if(e<error)
				tjpt[k]=1;
		}

		for(int j=0;j<hideNum;j++)
		{
			pp[j]=0.0;
			for(int k=0;k<outNum;k++)
				pp[j]=pp[j]+qq[k]*w1[j][k];
			pp[j]=pp[j]*x1[j]*(1-x1[j]);//�������У�����

			for(int i=0;i<inNum;i++)
				w[i][j]=w[i][j]+rate_w*pp[j]*x[i];//��һ�ε�������������֮���������Ȩ
		}

		for(int k=0;k<outNum;k++)
			b2[k]=b2[k]+rate_b2*qq[k];//��һ�ε�������������֮�������ֵ
		for(int j=0;j<hideNum;j++)
			b1[j]=b1[j]+rate_b1*pp[j];//��һ�ε�������������֮�������ֵ

	}//end isamp��Ʒѭ��

}
///////////////////////////end train/////////////////////////////

/////////////////////////////////////////////////////////////////

double * BpNet::sim(double *psim)
{ 
	for(int i=0;i<inNum;i++)
		x[i]=psim[i];
	for(int j=0;j<hideNum;j++)
	{
		o1[j]=0.0;

		for(int i=0;i<inNum;i++)
			o1[j]=o1[j]+w[i][j]*x[i];//���������Ԫ����ֵ
		x1[j]=1.0/(1.0+exp(-o1[j]-b1[j]));//���������Ԫ���
	}

	for(int k=0;k<outNum;k++)
	{
		o2[k]=0.0;
		for(int j=0;j<hideNum;j++)
			o2[k]=o2[k]+w1[j][k]*x1[j];//��������Ԫ����ֵ
		x2[k]=1.0/(1.0+exp(-o2[k]-b2[k]));//��������Ԫ���
	} 

	for(int k=0;k<outNum;k++)
	{
		shuchu[k]=x2[k];
	} 
	return x2;
}

void BpNet::SaveToFile(CString str)
{
	CFile flWeight;

	flWeight.Open(str,CFile::modeCreate | CFile::modeReadWrite);

	for(int i=0;i<MAX_IN_NUM;i++)
	{
		flWeight.Write(w[i],MAX_HIDE_NUM*sizeof(double));
	}

	for(int i=0;i<MAX_HIDE_NUM;i++)
	{
		flWeight.Write(w1[i],MAX_OUT_NUM*sizeof(double));
	}

	flWeight.Write(b1,MAX_HIDE_NUM * sizeof(double));
	flWeight.Write(b2,MAX_OUT_NUM*sizeof(double));

	flWeight.Close();
}

void BpNet::LoadFromFile(CString str)
{
	CFile flWeight;
	flWeight.Open(str,CFile::modeRead);

	for(int i=0;i<MAX_IN_NUM;i++)
	{
		flWeight.Read(w[i],MAX_HIDE_NUM*sizeof(double));
	}

	for(int i=0;i<MAX_HIDE_NUM;i++)
	{
		flWeight.Read(w1[i],MAX_OUT_NUM*sizeof(double));
	}

	flWeight.Read(b1,MAX_HIDE_NUM * sizeof(double));
	flWeight.Read(b2,MAX_OUT_NUM*sizeof(double));

	flWeight.Close();
}
