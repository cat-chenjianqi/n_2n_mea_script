#ifndef __CINT__
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <TFile.h>
#include <TH1.h>
#include <TTree.h>
#endif

using namespace std;

void pixie_to_root() {

	TString pixie_file_location="G:\\project\\n_2n_exp_direct_beam\\origin_data\\118\\";
	TString root_file_location="G:\\project\\n_2n_exp_direct_beam\\origin_data\\118\\";


	ifstream infile(pixie_file_location + "test_0118.bin",ios::binary);
	if(!infile) {
		cerr<<"open error!"<<endl;
		abort();
	}
	infile.seekg (0,ios::cur);
	infile.seekg (0,ios::end);
	Int_t size=infile.tellg();
	//cout<<"size="<<size<<endl;
	infile.seekg (0,ios::beg);
	Int_t BinSize2=0;
	// Variable
	UShort_t N_BUF_NDATA;
	UShort_t N_BUF_MODNUM;
	UShort_t N_BUF_FORMAT;
	UShort_t N_BUF_TIMEHI;
	UShort_t N_BUF_TIMEMI;
	UShort_t N_BUF_TIMELO;
	// Branch
	UShort_t N_EVT_PATTERN=0;
	UShort_t N_EVT_TIMEHI=0;
	UShort_t N_EVT_TIMELO=0;
	UShort_t N_CHAN_TRIGTIME_1=0;
	//moudle1
	UShort_t N_CHAN_ENERGY_1=0;
	UShort_t N_XIAPSA_1=0;
	UShort_t N_USERPSA_1=0;
	UShort_t N_CHAN_TRIGTIME_2=0;
	UShort_t N_CHAN_ENERGY_2=0;
	UShort_t N_XIAPSA_2=0;
	UShort_t N_USERPSA_2=0;
	UShort_t N_CHAN_TRIGTIME_3=0;
	UShort_t N_CHAN_ENERGY_3=0;
	UShort_t N_XIAPSA_3=0;
	UShort_t N_USERPSA_3=0;
	UShort_t N_CHAN_TRIGTIME_4=0;
	UShort_t N_CHAN_ENERGY_4=0;
	UShort_t N_XIAPSA_4=0;
	UShort_t N_USERPSA_4=0;
	UShort_t N_CHAN_TRIGTIME_5=0;
	//moudle 2
	UShort_t N_CHAN_ENERGY_5=0;
	UShort_t N_XIAPSA_5=0;
	UShort_t N_USERPSA_5=0;
	UShort_t N_CHAN_TRIGTIME_6=0;
	UShort_t N_CHAN_ENERGY_6=0;
	UShort_t N_XIAPSA_6=0;
	UShort_t N_USERPSA_6=0;
	UShort_t N_CHAN_TRIGTIME_7=0;
	UShort_t N_CHAN_ENERGY_7=0;
	UShort_t N_XIAPSA_7=0;
	UShort_t N_USERPSA_7=0;
	UShort_t N_CHAN_TRIGTIME_8=0;
	UShort_t N_CHAN_ENERGY_8=0;
	UShort_t N_XIAPSA_8=0;
	UShort_t N_USERPSA_8=0;
	Double_t D_N_CHAN_TRIGTIME_1=0.0;
	Double_t D_N_CHAN_TRIGTIME_2=0.0;
	Double_t D_N_CHAN_TRIGTIME_3=0.0;
	Double_t D_N_CHAN_TRIGTIME_4=0.0;
	Double_t D_N_CHAN_TRIGTIME_5=0.0;
	Double_t D_N_CHAN_TRIGTIME_6=0.0;
	Double_t D_N_CHAN_TRIGTIME_7=0.0;
	Double_t D_N_CHAN_TRIGTIME_8=0.0;
	// File Result1
	TFile f(root_file_location + "test_0118.root","RECREATE");
	TTree *Tree_Result1= new TTree("Tree_Result1","Tree for record wave dump");
	// Tree_Result1
	Tree_Result1->Branch("N_CHAN_TRIGTIME_1",&N_CHAN_TRIGTIME_1,"N_CHAN_TRIGTIME_1/s");
	Tree_Result1->Branch("N_CHAN_ENERGY_1",&N_CHAN_ENERGY_1,"N_CHAN_ENERGY_1/s");
	Tree_Result1->Branch("D_N_CHAN_TRIGTIME_1",&D_N_CHAN_TRIGTIME_1,"D_N_CHAN_TRIGTIME_1/D");
	// File Result2
	TTree *Tree_Result2= new TTree("Tree_Result2","Tree for record wave dump");
	// Tree Result2
	Tree_Result2->Branch("N_CHAN_TRIGTIME_2",&N_CHAN_TRIGTIME_2,"N_CHAN_TRIGTIME_2/s");
	Tree_Result2->Branch("N_CHAN_ENERGY_2",&N_CHAN_ENERGY_2,"N_CHAN_ENERGY_2/s");
	Tree_Result2->Branch("D_N_CHAN_TRIGTIME_2",&D_N_CHAN_TRIGTIME_2,"D_N_CHAN_TRIGTIME_2/D");
	// File Result3
	TTree *Tree_Result3= new TTree("Tree_Result3","Tree for record wave dump");
	// Tree Result3
	Tree_Result3->Branch("N_CHAN_TRIGTIME_3",&N_CHAN_TRIGTIME_3,"N_CHAN_TRIGTIME_3/s");
	Tree_Result3->Branch("N_CHAN_ENERGY_3",&N_CHAN_ENERGY_3,"N_CHAN_ENERGY_3/s");
	Tree_Result3->Branch("D_N_CHAN_TRIGTIME_3",&D_N_CHAN_TRIGTIME_3,"D_N_CHAN_TRIGTIME_3/D");
	// File Result4
	TTree *Tree_Result4= new TTree("Tree_Result4","Tree for record wave dump");
	// Tree Result4
	Tree_Result4->Branch("N_CHAN_TRIGTIME_4",&N_CHAN_TRIGTIME_4,"N_CHAN_TRIGTIME_4/s");
	Tree_Result4->Branch("N_CHAN_ENERGY_4",&N_CHAN_ENERGY_4,"N_CHAN_ENERGY_4/s");
	Tree_Result4->Branch("D_N_CHAN_TRIGTIME_4",&D_N_CHAN_TRIGTIME_4,"D_N_CHAN_TRIGTIME_4/D");
	// File Result5
	TTree *Tree_Result5= new TTree("Tree_Result5","Tree for record wave dump");
	// Tree Result5
	Tree_Result5->Branch("N_CHAN_TRIGTIME_5",&N_CHAN_TRIGTIME_5,"N_CHAN_TRIGTIME_5/s");
	Tree_Result5->Branch("N_CHAN_ENERGY_5",&N_CHAN_ENERGY_5,"N_CHAN_ENERGY_5/s");
	Tree_Result5->Branch("D_N_CHAN_TRIGTIME_5",&D_N_CHAN_TRIGTIME_5,"D_N_CHAN_TRIGTIME_5/D");
	// File Result6
	TTree *Tree_Result6= new TTree("Tree_Result6","Tree for record wave dump");
	// Tree Result6
	Tree_Result6->Branch("N_CHAN_TRIGTIME_6",&N_CHAN_TRIGTIME_6,"N_CHAN_TRIGTIME_6/s");
	Tree_Result6->Branch("N_CHAN_ENERGY_6",&N_CHAN_ENERGY_6,"N_CHAN_ENERGY_6/s");
	Tree_Result6->Branch("D_N_CHAN_TRIGTIME_6",&D_N_CHAN_TRIGTIME_6,"D_N_CHAN_TRIGTIME_6/D");
	// File Result7
	TTree *Tree_Result7= new TTree("Tree_Result7","Tree for record wave dump");
	// Tree Result7
	Tree_Result7->Branch("N_CHAN_TRIGTIME_7",&N_CHAN_TRIGTIME_7,"N_CHAN_TRIGTIME_7/s");
	Tree_Result7->Branch("N_CHAN_ENERGY_7",&N_CHAN_ENERGY_7,"N_CHAN_ENERGY_7/s");
	Tree_Result7->Branch("D_N_CHAN_TRIGTIME_7",&D_N_CHAN_TRIGTIME_7,"D_N_CHAN_TRIGTIME_7/D");
	// File Result8
	TTree *Tree_Result8= new TTree("Tree_Result8","Tree for record wave dump");
	// Tree Result8
	Tree_Result8->Branch("N_CHAN_TRIGTIME_8",&N_CHAN_TRIGTIME_8,"N_CHAN_TRIGTIME_8/s");
	Tree_Result8->Branch("N_CHAN_ENERGY_8",&N_CHAN_ENERGY_8,"N_CHAN_ENERGY_8/s");
	Tree_Result8->Branch("D_N_CHAN_TRIGTIME_8",&D_N_CHAN_TRIGTIME_8,"D_N_CHAN_TRIGTIME_8/D");
	while (BinSize2<size) {
		//header1
		struct header1 {
			UShort_t BUF_NDATA_1;
			UShort_t BUF_MODNUM_1;
			UShort_t BUF_FORMAT_1;
			UShort_t BUF_TIMEHI_1;
			UShort_t BUF_TIMEMI_1;
			UShort_t BUF_TIMELO_1;
		}
		header1_t;
		infile.read((char *)&header1_t,12);
		N_BUF_NDATA=header1_t.BUF_NDATA_1;
		N_BUF_MODNUM=header1_t.BUF_MODNUM_1;
		N_BUF_FORMAT=header1_t.BUF_FORMAT_1;
		N_BUF_TIMEHI=header1_t.BUF_TIMEHI_1;
		N_BUF_TIMEMI=header1_t.BUF_TIMEMI_1;
		N_BUF_TIMELO=header1_t.BUF_TIMELO_1;
		Int_t BinSize1;
		BinSize1=(header1_t.BUF_NDATA_1)-6;
		BinSize2+=(header1_t.BUF_NDATA_1)*2;
		if (header1_t.BUF_MODNUM_1==0)// moudle 1
		{
			struct data {
				UShort_t EVT_PATTERN;
				UShort_t EVT_TIMEHI;
				UShort_t EVT_TIMELO;
			} data_t;
			struct channel {
				UShort_t CHAN_TRIGTIME_1;
				UShort_t CHAN_ENERGY_1;
				UShort_t CHAN_TRIGTIME_2;
				UShort_t CHAN_ENERGY_2;
				UShort_t CHAN_TRIGTIME_3;
				UShort_t CHAN_ENERGY_3;
				UShort_t CHAN_TRIGTIME_4;
				UShort_t CHAN_ENERGY_4;
			} channel_t;

			Int_t i=0;
			Int_t j=0;
			while(i+j<BinSize1) {
				i+=3;
				infile.read((char *)&data_t,6);
				N_EVT_PATTERN=data_t.EVT_PATTERN;
				N_EVT_TIMEHI=data_t.EVT_TIMEHI;
				N_EVT_TIMELO=data_t.EVT_TIMELO;
				Int_t s;
				s=(N_EVT_PATTERN&0b0000111100000000)>>8;
				N_EVT_TIMEHI=data_t.EVT_TIMEHI;
				if(s==1) {
					infile.read((char *)&channel_t,4);
					j+=2;
					N_CHAN_TRIGTIME_1=channel_t.CHAN_TRIGTIME_1;
					N_CHAN_ENERGY_1=channel_t.CHAN_ENERGY_1;
					D_N_CHAN_TRIGTIME_1=N_CHAN_TRIGTIME_1;
					D_N_CHAN_TRIGTIME_1+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_1+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_1*=1E-6/75;
					Tree_Result1->Fill();
				}
				else if(s==2) {
					infile.read((char *)&channel_t,4);
					j+=2;
					N_CHAN_TRIGTIME_2=channel_t.CHAN_TRIGTIME_1;
					N_CHAN_ENERGY_2=channel_t.CHAN_ENERGY_1;
					D_N_CHAN_TRIGTIME_2=N_CHAN_TRIGTIME_2;
					D_N_CHAN_TRIGTIME_2+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_2+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_2*=1E-6/75;
					Tree_Result2->Fill();
				}
				else if(s==3) {
					infile.read((char *)&channel_t,8);
					j+=4;
					N_CHAN_TRIGTIME_1=channel_t.CHAN_TRIGTIME_1;
					N_CHAN_ENERGY_1=channel_t.CHAN_ENERGY_1;
					D_N_CHAN_TRIGTIME_1=N_CHAN_TRIGTIME_1*1.000000000;
					D_N_CHAN_TRIGTIME_1+=N_EVT_TIMEHI*pow(2,16)*1.000000000;
					D_N_CHAN_TRIGTIME_1+=N_BUF_TIMEHI*pow(2,32)*1.000000000;
					D_N_CHAN_TRIGTIME_1*=1E-6/75;
					N_CHAN_TRIGTIME_2=channel_t.CHAN_TRIGTIME_2;
					N_CHAN_ENERGY_2=channel_t.CHAN_ENERGY_2;
					D_N_CHAN_TRIGTIME_2=N_CHAN_TRIGTIME_2*1.000000000;
					D_N_CHAN_TRIGTIME_2+=N_EVT_TIMEHI*pow(2,16)*1.0000000000;
					D_N_CHAN_TRIGTIME_2+=N_BUF_TIMEHI*pow(2,32)*1.0000000000;
					D_N_CHAN_TRIGTIME_2*=1E-6/75;
					Tree_Result1->Fill();
					Tree_Result2->Fill();
				}
				else if(s==4) {
					infile.read((char *)&channel_t,4);
					j+=2;
					N_CHAN_TRIGTIME_3=channel_t.CHAN_TRIGTIME_1;
					N_CHAN_ENERGY_3=channel_t.CHAN_ENERGY_1;
					D_N_CHAN_TRIGTIME_3=N_CHAN_TRIGTIME_3*1.000000000;
					D_N_CHAN_TRIGTIME_3+=N_EVT_TIMEHI*pow(2,16)*1.00000000000;
					D_N_CHAN_TRIGTIME_3+=N_BUF_TIMEHI*pow(2,32)*1.00000000000;
					D_N_CHAN_TRIGTIME_3*=1E-6/75;
					Tree_Result3->Fill();
				}
				else if(s==5) {
					infile.read((char *)&channel_t,8);
					j+=4;
					N_CHAN_TRIGTIME_1=channel_t.CHAN_TRIGTIME_1;
					N_CHAN_ENERGY_1=channel_t.CHAN_ENERGY_1;
					D_N_CHAN_TRIGTIME_1=N_CHAN_TRIGTIME_1;
					D_N_CHAN_TRIGTIME_1+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_1+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_1*=1E-6/75;
					//  N_XIAPSA_1=channel_t.XIAPSA_1;  
					//  N_USERPSA_1=channel_t.USERPSA_1;
					N_CHAN_TRIGTIME_3=channel_t.CHAN_TRIGTIME_2;
					N_CHAN_ENERGY_3=channel_t.CHAN_ENERGY_2;
					D_N_CHAN_TRIGTIME_3=N_CHAN_TRIGTIME_3;
					D_N_CHAN_TRIGTIME_3+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_3+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_3*=1E-6/75;
					Tree_Result1->Fill();
					Tree_Result3->Fill();
				}
				else if(s==6) {
					infile.read((char *)&channel_t,8);
					j+=4;
					N_CHAN_TRIGTIME_2=channel_t.CHAN_TRIGTIME_1;
					N_CHAN_ENERGY_2=channel_t.CHAN_ENERGY_1;
					D_N_CHAN_TRIGTIME_2=N_CHAN_TRIGTIME_2;
					D_N_CHAN_TRIGTIME_2+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_2+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_2*=1E-6/75;
					N_CHAN_TRIGTIME_3=channel_t.CHAN_TRIGTIME_2;
					N_CHAN_ENERGY_3=channel_t.CHAN_ENERGY_2;
					D_N_CHAN_TRIGTIME_3=N_CHAN_TRIGTIME_3;
					D_N_CHAN_TRIGTIME_3+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_3+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_3*=1E-6/75;
					Tree_Result2->Fill();
					Tree_Result3->Fill();
				}
				else if(s==7) {
					infile.read((char *)&channel_t,12);
					j+=6;
					N_CHAN_TRIGTIME_1=channel_t.CHAN_TRIGTIME_1;
					N_CHAN_ENERGY_1=channel_t.CHAN_ENERGY_1;
					D_N_CHAN_TRIGTIME_1=N_CHAN_TRIGTIME_1;
					D_N_CHAN_TRIGTIME_1+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_1+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_1*=1E-6/75;
					N_CHAN_TRIGTIME_2=channel_t.CHAN_TRIGTIME_2;
					N_CHAN_ENERGY_2=channel_t.CHAN_ENERGY_2;
					D_N_CHAN_TRIGTIME_2=N_CHAN_TRIGTIME_2;
					D_N_CHAN_TRIGTIME_2+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_2+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_2*=1E-6/75;
					N_CHAN_TRIGTIME_3=channel_t.CHAN_TRIGTIME_3;
					N_CHAN_ENERGY_3=channel_t.CHAN_ENERGY_3;
					D_N_CHAN_TRIGTIME_3=N_CHAN_TRIGTIME_3;
					D_N_CHAN_TRIGTIME_3+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_3+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_3*=1E-6/75;
					Tree_Result1->Fill();
					Tree_Result2->Fill();
					Tree_Result3->Fill();
				}
				else if(s==8) {
					infile.read((char *)&channel_t,4);
					j+=2;
					N_CHAN_TRIGTIME_4=channel_t.CHAN_TRIGTIME_1;
					N_CHAN_ENERGY_4=channel_t.CHAN_ENERGY_1;
					D_N_CHAN_TRIGTIME_4=N_CHAN_TRIGTIME_4*1.000000000;
					D_N_CHAN_TRIGTIME_4+=N_EVT_TIMEHI*pow(2,16)*1.000000000;
					D_N_CHAN_TRIGTIME_4+=N_BUF_TIMEHI*pow(2,32)*1.000000000;
					D_N_CHAN_TRIGTIME_4*=1E-6/75;
					Tree_Result4->Fill();
				}
				else if(s==9) {
					infile.read((char *)&channel_t,8);
					j+=4;
					N_CHAN_TRIGTIME_1=channel_t.CHAN_TRIGTIME_1;
					N_CHAN_ENERGY_1=channel_t.CHAN_ENERGY_1;
					D_N_CHAN_TRIGTIME_1=N_CHAN_TRIGTIME_1;
					D_N_CHAN_TRIGTIME_1+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_1+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_1*=1E-6/75;
					N_CHAN_TRIGTIME_4=channel_t.CHAN_TRIGTIME_2;
					N_CHAN_ENERGY_4=channel_t.CHAN_ENERGY_2;
					D_N_CHAN_TRIGTIME_4=N_CHAN_TRIGTIME_4;
					D_N_CHAN_TRIGTIME_4+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_4+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_4*=1E-6/75;
					Tree_Result1->Fill();
					Tree_Result4->Fill();
				}
				else if(s==10) {
					infile.read((char *)&channel_t,8);
					j+=4;
					N_CHAN_TRIGTIME_2=channel_t.CHAN_TRIGTIME_1;
					N_CHAN_ENERGY_2=channel_t.CHAN_ENERGY_1;
					D_N_CHAN_TRIGTIME_2=N_CHAN_TRIGTIME_2;
					D_N_CHAN_TRIGTIME_2+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_2+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_2*=1E-6/75;
					N_CHAN_TRIGTIME_4=channel_t.CHAN_TRIGTIME_2;
					N_CHAN_ENERGY_4=channel_t.CHAN_ENERGY_2;
					D_N_CHAN_TRIGTIME_4=N_CHAN_TRIGTIME_4;
					D_N_CHAN_TRIGTIME_4+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_4+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_4*=1E-6/75;
					Tree_Result2->Fill();
					Tree_Result4->Fill();
				}
				else if(s==11) {
					infile.read((char *)&channel_t,12);
					j+=6;
					N_CHAN_TRIGTIME_1=channel_t.CHAN_TRIGTIME_1;
					N_CHAN_ENERGY_1=channel_t.CHAN_ENERGY_1;
					D_N_CHAN_TRIGTIME_1=N_CHAN_TRIGTIME_1;
					D_N_CHAN_TRIGTIME_1+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_1+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_1*=1E-6/75;
					N_CHAN_TRIGTIME_2=channel_t.CHAN_TRIGTIME_2;
					N_CHAN_ENERGY_2=channel_t.CHAN_ENERGY_2;
					D_N_CHAN_TRIGTIME_2=N_CHAN_TRIGTIME_2;
					D_N_CHAN_TRIGTIME_2+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_2+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_2*=1E-6/75;
					N_CHAN_TRIGTIME_4=channel_t.CHAN_TRIGTIME_3;
					N_CHAN_ENERGY_4=channel_t.CHAN_ENERGY_3;
					D_N_CHAN_TRIGTIME_4=N_CHAN_TRIGTIME_4;
					D_N_CHAN_TRIGTIME_4+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_4+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_4*=1E-6/75;
					Tree_Result1->Fill();
					Tree_Result2->Fill();
					Tree_Result4->Fill();
				}
				else if(s==12) {
					infile.read((char *)&channel_t,8);
					j+=4;
					N_CHAN_TRIGTIME_3=channel_t.CHAN_TRIGTIME_1;
					N_CHAN_ENERGY_3=channel_t.CHAN_ENERGY_1;
					D_N_CHAN_TRIGTIME_3=N_CHAN_TRIGTIME_3;
					D_N_CHAN_TRIGTIME_3+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_3+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_3*=1E-6/75;
					N_CHAN_TRIGTIME_4=channel_t.CHAN_TRIGTIME_2;
					N_CHAN_ENERGY_4=channel_t.CHAN_ENERGY_2;
					D_N_CHAN_TRIGTIME_4=N_CHAN_TRIGTIME_4;
					D_N_CHAN_TRIGTIME_4+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_4+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_4*=1E-6/75;
					Tree_Result3->Fill();
					Tree_Result4->Fill();
				}
				else if(s==13) {
					infile.read((char *)&channel_t,12);
					j+=6;
					N_CHAN_TRIGTIME_1=channel_t.CHAN_TRIGTIME_1;
					N_CHAN_ENERGY_1=channel_t.CHAN_ENERGY_1;
					D_N_CHAN_TRIGTIME_1=N_CHAN_TRIGTIME_1;
					D_N_CHAN_TRIGTIME_1+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_1+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_1*=1E-6/75;
					N_CHAN_TRIGTIME_3=channel_t.CHAN_TRIGTIME_2;
					N_CHAN_ENERGY_3=channel_t.CHAN_ENERGY_2;
					D_N_CHAN_TRIGTIME_3=N_CHAN_TRIGTIME_3;
					D_N_CHAN_TRIGTIME_3+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_3+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_3*=1E-6/75;
					N_CHAN_TRIGTIME_4=channel_t.CHAN_TRIGTIME_3;
					N_CHAN_ENERGY_4=channel_t.CHAN_ENERGY_3;
					D_N_CHAN_TRIGTIME_4=N_CHAN_TRIGTIME_4;
					D_N_CHAN_TRIGTIME_4+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_4+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_4*=1E-6/75;
					Tree_Result1->Fill();
					Tree_Result3->Fill();
					Tree_Result4->Fill();
				}
				else if(s==14) {
					infile.read((char *)&channel_t,12);
					j+=6;
					N_CHAN_TRIGTIME_2=channel_t.CHAN_TRIGTIME_1;
					N_CHAN_ENERGY_2=channel_t.CHAN_ENERGY_1;
					D_N_CHAN_TRIGTIME_2=N_CHAN_TRIGTIME_2;
					D_N_CHAN_TRIGTIME_2+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_2+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_2*=1E-6/75;
					N_CHAN_TRIGTIME_3=channel_t.CHAN_TRIGTIME_2;
					N_CHAN_ENERGY_3=channel_t.CHAN_ENERGY_2;
					D_N_CHAN_TRIGTIME_3=N_CHAN_TRIGTIME_3;
					D_N_CHAN_TRIGTIME_3+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_3+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_3*=1E-6/75;
					N_CHAN_TRIGTIME_4=channel_t.CHAN_TRIGTIME_3;
					N_CHAN_ENERGY_4=channel_t.CHAN_ENERGY_3;
					D_N_CHAN_TRIGTIME_4=N_CHAN_TRIGTIME_4;
					D_N_CHAN_TRIGTIME_4+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_4+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_4*=1E-6/75;
					Tree_Result2->Fill();
					Tree_Result3->Fill();
					Tree_Result4->Fill();
				}
				else {
					infile.read((char *)&channel_t,16);
					j+=8;
					N_CHAN_TRIGTIME_1=channel_t.CHAN_TRIGTIME_1 ;
					N_CHAN_ENERGY_1=channel_t.CHAN_ENERGY_1;
					D_N_CHAN_TRIGTIME_1=N_CHAN_TRIGTIME_1;
					D_N_CHAN_TRIGTIME_1+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_1+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_1*=1E-6/75;
					N_CHAN_TRIGTIME_2=channel_t.CHAN_TRIGTIME_2;
					N_CHAN_ENERGY_2=channel_t.CHAN_ENERGY_2;
					D_N_CHAN_TRIGTIME_2=N_CHAN_TRIGTIME_2;
					D_N_CHAN_TRIGTIME_2+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_2+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_2*=1E-6/75;
					//  N_XIAPSA_2=channel_t.XIAPSA_2;  
					//  N_USERPSA_2=channel_t.USERPSA_2;
					N_CHAN_TRIGTIME_3=channel_t.CHAN_TRIGTIME_3;
					N_CHAN_ENERGY_3=channel_t.CHAN_ENERGY_3;
					D_N_CHAN_TRIGTIME_3=N_CHAN_TRIGTIME_3;
					D_N_CHAN_TRIGTIME_3+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_3+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_3*=1E-6/75;
					//  N_XIAPSA_3=channel_t.XIAPSA_3;  
					//  N_USERPSA_3=channel_t.USERPSA_3;
					N_CHAN_TRIGTIME_4=channel_t.CHAN_TRIGTIME_4;
					N_CHAN_ENERGY_4=channel_t.CHAN_ENERGY_4;
					D_N_CHAN_TRIGTIME_4=N_CHAN_TRIGTIME_4;
					D_N_CHAN_TRIGTIME_4+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_4+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_4*=1E-6/75;
					Tree_Result1->Fill();
					Tree_Result2->Fill();
					Tree_Result3->Fill();
					Tree_Result4->Fill();
				}
				if(infile.peek()==EOF) {
					goto try1;
				}
			} //while(i+j<BinSize1) crospond to one buffer
		} // correspond to moudle 1 
		else {
			struct data2 {
				UShort_t EVT_PATTERN;
				UShort_t EVT_TIMEHI;
				UShort_t EVT_TIMELO;
			} data2_t;
			struct channel2 {
				UShort_t CHAN_TRIGTIME_5;
				UShort_t CHAN_ENERGY_5;
				UShort_t CHAN_TRIGTIME_6;
				UShort_t CHAN_ENERGY_6;
				UShort_t CHAN_TRIGTIME_7;
				UShort_t CHAN_ENERGY_7;
				UShort_t CHAN_TRIGTIME_8;
				UShort_t CHAN_ENERGY_8;
			} channel2_t;
			//cout<<"sizeof(header_t)= "<<sizeof(data_t)<<endl;
			//for(Int_t i=0;i<BinSize1/7;i++)
			//{
			Int_t i=0;
			Int_t j=0;
			while(i+j<BinSize1) {
				i+=3;
				infile.read((char *)&data2_t,6);
				N_EVT_PATTERN=data2_t.EVT_PATTERN;
				N_EVT_TIMEHI=data2_t.EVT_TIMEHI;
				N_EVT_TIMELO=data2_t.EVT_TIMELO;
				Int_t s;
				s=(N_EVT_PATTERN&0b0000111100000000)>>8;
				//  s=(N_EVT_PATTERN&0x0070)>>4;
				//  cout<<s<<endl;
				if(s==1) {
					infile.read((char *)&channel2_t,4);
					j+=2;
					N_CHAN_TRIGTIME_5=channel2_t.CHAN_TRIGTIME_5;
					N_CHAN_ENERGY_5=channel2_t.CHAN_ENERGY_5;
					D_N_CHAN_TRIGTIME_5=N_CHAN_TRIGTIME_5*1.000000000;
					D_N_CHAN_TRIGTIME_5+=N_EVT_TIMEHI*pow(2,16)*1.000000000;
					D_N_CHAN_TRIGTIME_5+=N_BUF_TIMEHI*pow(2,32)*1.000000000;
					D_N_CHAN_TRIGTIME_5*=1E-6/75;
					Tree_Result5->Fill();
				}
				else if(s==2) {
					infile.read((char *)&channel2_t,4);
					j+=2;
					N_CHAN_TRIGTIME_6=channel2_t.CHAN_TRIGTIME_5;
					N_CHAN_ENERGY_6=channel2_t.CHAN_ENERGY_5;
					D_N_CHAN_TRIGTIME_6=N_CHAN_TRIGTIME_6;
					D_N_CHAN_TRIGTIME_6+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_6+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_6*=1E-6/75;
					Tree_Result6->Fill();
				}
				else if(s==3) {
					infile.read((char *)&channel2_t,8);
					j+=4;
					N_CHAN_TRIGTIME_5=channel2_t.CHAN_TRIGTIME_5;
					N_CHAN_ENERGY_5=channel2_t.CHAN_ENERGY_5;
					D_N_CHAN_TRIGTIME_5=N_CHAN_TRIGTIME_5;
					D_N_CHAN_TRIGTIME_5+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_5+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_5*=1E-6/75;
					N_CHAN_TRIGTIME_6=channel2_t.CHAN_TRIGTIME_6;
					N_CHAN_ENERGY_6=channel2_t.CHAN_ENERGY_6;
					D_N_CHAN_TRIGTIME_6=N_CHAN_TRIGTIME_6;
					D_N_CHAN_TRIGTIME_6+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_6+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_6*=1E-6/75;
					Tree_Result5->Fill();
					Tree_Result6->Fill();
				}
				else if(s==4) {
					infile.read((char *)&channel2_t,4);
					j+=2;
					N_CHAN_TRIGTIME_7=channel2_t.CHAN_TRIGTIME_5;
					N_CHAN_ENERGY_7=channel2_t.CHAN_ENERGY_5;
					D_N_CHAN_TRIGTIME_7=N_CHAN_TRIGTIME_7;
					D_N_CHAN_TRIGTIME_7+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_7+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_7*=1E-6/75;
					Tree_Result7->Fill();
				}
				else if(s==5) {
					infile.read((char *)&channel2_t,8);
					j+=4;
					N_CHAN_TRIGTIME_5=channel2_t.CHAN_TRIGTIME_5;
					N_CHAN_ENERGY_5=channel2_t.CHAN_ENERGY_5;
					D_N_CHAN_TRIGTIME_5=N_CHAN_TRIGTIME_5;
					D_N_CHAN_TRIGTIME_5+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_5+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_5*=1E-6/75;
					N_CHAN_TRIGTIME_7=channel2_t.CHAN_TRIGTIME_6;
					N_CHAN_ENERGY_7=channel2_t.CHAN_ENERGY_6;
					D_N_CHAN_TRIGTIME_7=N_CHAN_TRIGTIME_7;
					D_N_CHAN_TRIGTIME_7+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_7+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_7*=1E-6/75;
					Tree_Result5->Fill();
					Tree_Result7->Fill();
				}
				else if(s==6) {
					infile.read((char *)&channel2_t,8);
					j+=4;
					N_CHAN_TRIGTIME_6=channel2_t.CHAN_TRIGTIME_5;
					N_CHAN_ENERGY_6=channel2_t.CHAN_ENERGY_5;
					D_N_CHAN_TRIGTIME_6=N_CHAN_TRIGTIME_6;
					D_N_CHAN_TRIGTIME_6+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_6+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_6*=1E-6/75;
					N_CHAN_TRIGTIME_7=channel2_t.CHAN_TRIGTIME_6;
					N_CHAN_ENERGY_7=channel2_t.CHAN_ENERGY_6;
					D_N_CHAN_TRIGTIME_7=N_CHAN_TRIGTIME_7;
					D_N_CHAN_TRIGTIME_7+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_7+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_7*=1E-6/75;
					Tree_Result6->Fill();
					Tree_Result7->Fill();
				}
				else if(s==7) {
					infile.read((char *)&channel2_t,12);
					j+=6;
					N_CHAN_TRIGTIME_5=channel2_t.CHAN_TRIGTIME_5;
					N_CHAN_ENERGY_5=channel2_t.CHAN_ENERGY_5;
					D_N_CHAN_TRIGTIME_5=N_CHAN_TRIGTIME_5;
					D_N_CHAN_TRIGTIME_5+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_5+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_5*=1E-6/75;
					N_CHAN_TRIGTIME_6=channel2_t.CHAN_TRIGTIME_6;
					N_CHAN_ENERGY_6=channel2_t.CHAN_ENERGY_6;
					D_N_CHAN_TRIGTIME_6=N_CHAN_TRIGTIME_6;
					D_N_CHAN_TRIGTIME_6+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_6+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_6*=1E-6/75;
					N_CHAN_TRIGTIME_7=channel2_t.CHAN_TRIGTIME_7;
					N_CHAN_ENERGY_7=channel2_t.CHAN_ENERGY_7;
					D_N_CHAN_TRIGTIME_7=N_CHAN_TRIGTIME_7;
					D_N_CHAN_TRIGTIME_7+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_7+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_7*=1E-6/75;
					Tree_Result5->Fill();
					Tree_Result6->Fill();
					Tree_Result7->Fill();
				}
				else if(s==8) {
					infile.read((char *)&channel2_t,4);
					j+=2;
					N_CHAN_TRIGTIME_8=channel2_t.CHAN_TRIGTIME_5;
					N_CHAN_ENERGY_8=channel2_t.CHAN_ENERGY_5;
					D_N_CHAN_TRIGTIME_8=N_CHAN_TRIGTIME_8;
					D_N_CHAN_TRIGTIME_8+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_8+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_8*=1E-6/75;
					Tree_Result8->Fill();
				}
				else if(s==9) {
					infile.read((char *)&channel2_t,8);
					j+=4;
					N_CHAN_TRIGTIME_5=channel2_t.CHAN_TRIGTIME_5;
					N_CHAN_ENERGY_5=channel2_t.CHAN_ENERGY_5;
					D_N_CHAN_TRIGTIME_5=N_CHAN_TRIGTIME_5;
					D_N_CHAN_TRIGTIME_5+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_5+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_5*=1E-6/75;
					N_CHAN_TRIGTIME_8=channel2_t.CHAN_TRIGTIME_6;
					N_CHAN_ENERGY_8=channel2_t.CHAN_ENERGY_6;
					D_N_CHAN_TRIGTIME_8=N_CHAN_TRIGTIME_8;
					D_N_CHAN_TRIGTIME_8+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_8+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_8*=1E-6/75;
					Tree_Result5->Fill();
					Tree_Result8->Fill();
				}
				else if(s==10) {
					infile.read((char *)&channel2_t,8);
					j+=4;
					N_CHAN_TRIGTIME_6=channel2_t.CHAN_TRIGTIME_5;
					N_CHAN_ENERGY_6=channel2_t.CHAN_ENERGY_5;
					D_N_CHAN_TRIGTIME_6=N_CHAN_TRIGTIME_6;
					D_N_CHAN_TRIGTIME_6+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_6+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_6*=1E-6/75;
					//  N_XIAPSA_2=channel2_t.XIAPSA_2;  
					//  N_USERPSA_2=channel2_t.USERPSA_2;
					N_CHAN_TRIGTIME_8=channel2_t.CHAN_TRIGTIME_6;
					N_CHAN_ENERGY_8=channel2_t.CHAN_ENERGY_6;
					D_N_CHAN_TRIGTIME_8=N_CHAN_TRIGTIME_8;
					D_N_CHAN_TRIGTIME_8+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_8+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_8*=1E-6/75;
					Tree_Result6->Fill();
					Tree_Result8->Fill();
				}
				else if(s==11) {
					infile.read((char *)&channel2_t,12);
					j+=6;
					N_CHAN_TRIGTIME_5=channel2_t.CHAN_TRIGTIME_5;
					N_CHAN_ENERGY_5=channel2_t.CHAN_ENERGY_5;
					D_N_CHAN_TRIGTIME_5=N_CHAN_TRIGTIME_5;
					D_N_CHAN_TRIGTIME_5+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_5+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_5*=1E-6/75;
					N_CHAN_TRIGTIME_6=channel2_t.CHAN_TRIGTIME_6;
					N_CHAN_ENERGY_6=channel2_t.CHAN_ENERGY_6;
					D_N_CHAN_TRIGTIME_6=N_CHAN_TRIGTIME_6;
					D_N_CHAN_TRIGTIME_6+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_6+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_6*=1E-6/75;
					N_CHAN_TRIGTIME_8=channel2_t.CHAN_TRIGTIME_7;
					N_CHAN_ENERGY_8=channel2_t.CHAN_ENERGY_7;
					D_N_CHAN_TRIGTIME_8=N_CHAN_TRIGTIME_8;
					D_N_CHAN_TRIGTIME_8+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_8+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_8*=1E-6/75;
					Tree_Result5->Fill();
					Tree_Result6->Fill();
					Tree_Result8->Fill();
				}
				else if(s==12) {
					infile.read((char *)&channel2_t,8);
					j+=4;
					N_CHAN_TRIGTIME_7=channel2_t.CHAN_TRIGTIME_5;
					N_CHAN_ENERGY_7=channel2_t.CHAN_ENERGY_5;
					D_N_CHAN_TRIGTIME_7=N_CHAN_TRIGTIME_7;
					D_N_CHAN_TRIGTIME_7+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_7+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_7*=1E-6/75;
					N_CHAN_TRIGTIME_8=channel2_t.CHAN_TRIGTIME_6;
					N_CHAN_ENERGY_8=channel2_t.CHAN_ENERGY_6;
					D_N_CHAN_TRIGTIME_8=N_CHAN_TRIGTIME_8;
					D_N_CHAN_TRIGTIME_8+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_8+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_8*=1E-6/75;
					Tree_Result7->Fill();
					Tree_Result8->Fill();
				}
				else if(s==13) {
					infile.read((char *)&channel2_t,12);
					j+=6;
					N_CHAN_TRIGTIME_5=channel2_t.CHAN_TRIGTIME_5;
					N_CHAN_ENERGY_5=channel2_t.CHAN_ENERGY_5;
					D_N_CHAN_TRIGTIME_5=N_CHAN_TRIGTIME_5;
					D_N_CHAN_TRIGTIME_5+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_5+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_5*=1E-6/75;
					N_CHAN_TRIGTIME_7=channel2_t.CHAN_TRIGTIME_6;
					N_CHAN_ENERGY_7=channel2_t.CHAN_ENERGY_6;
					D_N_CHAN_TRIGTIME_7=N_CHAN_TRIGTIME_7;
					D_N_CHAN_TRIGTIME_7+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_7+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_7*=1E-6/75;
					N_CHAN_TRIGTIME_8=channel2_t.CHAN_TRIGTIME_7;
					N_CHAN_ENERGY_8=channel2_t.CHAN_ENERGY_7;
					D_N_CHAN_TRIGTIME_8=N_CHAN_TRIGTIME_8;
					D_N_CHAN_TRIGTIME_8+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_8+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_8*=1E-6/75;
					Tree_Result5->Fill();
					Tree_Result7->Fill();
					Tree_Result8->Fill();
				}
				else if(s==14) {
					infile.read((char *)&channel2_t,12);
					j+=6;
					N_CHAN_TRIGTIME_6=channel2_t.CHAN_TRIGTIME_5;
					N_CHAN_ENERGY_6=channel2_t.CHAN_ENERGY_5;
					D_N_CHAN_TRIGTIME_6=N_CHAN_TRIGTIME_6;
					D_N_CHAN_TRIGTIME_6+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_6+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_6*=1E-6/75;
					N_CHAN_TRIGTIME_7=channel2_t.CHAN_TRIGTIME_6;
					N_CHAN_ENERGY_7=channel2_t.CHAN_ENERGY_6;
					D_N_CHAN_TRIGTIME_7=N_CHAN_TRIGTIME_7;
					D_N_CHAN_TRIGTIME_7+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_7+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_7*=1E-6/75;
					N_CHAN_TRIGTIME_8=channel2_t.CHAN_TRIGTIME_7;
					N_CHAN_ENERGY_8=channel2_t.CHAN_ENERGY_7;
					D_N_CHAN_TRIGTIME_8=N_CHAN_TRIGTIME_8;
					D_N_CHAN_TRIGTIME_8+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_8+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_8*=1E-6/75;
					Tree_Result6->Fill();
					Tree_Result7->Fill();
					Tree_Result8->Fill();
				}
				else {
					infile.read((char *)&channel2_t,16);
					j+=8;
					N_CHAN_TRIGTIME_5=channel2_t.CHAN_TRIGTIME_5;
					N_CHAN_ENERGY_5=channel2_t.CHAN_ENERGY_5;
					D_N_CHAN_TRIGTIME_5=N_CHAN_TRIGTIME_5;
					D_N_CHAN_TRIGTIME_5+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_5+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_5*=1E-6/75;
					N_CHAN_TRIGTIME_6=channel2_t.CHAN_TRIGTIME_6;
					N_CHAN_ENERGY_6=channel2_t.CHAN_ENERGY_6;
					D_N_CHAN_TRIGTIME_6=N_CHAN_TRIGTIME_6;
					D_N_CHAN_TRIGTIME_6+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_6+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_6*=1E-6/75;
					N_CHAN_TRIGTIME_7=channel2_t.CHAN_TRIGTIME_7;
					N_CHAN_ENERGY_7=channel2_t.CHAN_ENERGY_7;
					D_N_CHAN_TRIGTIME_7=N_CHAN_TRIGTIME_7;
					D_N_CHAN_TRIGTIME_7+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_7+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_7*=1E-6/75;
					N_CHAN_TRIGTIME_8=channel2_t.CHAN_TRIGTIME_8;
					N_CHAN_ENERGY_8=channel2_t.CHAN_ENERGY_8;
					D_N_CHAN_TRIGTIME_8=N_CHAN_TRIGTIME_8;
					D_N_CHAN_TRIGTIME_8+=N_EVT_TIMEHI*pow(2,16);
					D_N_CHAN_TRIGTIME_8+=N_BUF_TIMEHI*pow(2,32);
					D_N_CHAN_TRIGTIME_8*=1E-6/75;
					Tree_Result5->Fill();
					Tree_Result6->Fill();
					Tree_Result7->Fill();
					Tree_Result8->Fill();
				}
				if(infile.peek()==EOF) {
					goto try1;
				}
			}//while(i+j<BinSize1) crospond to one buffer
		}
	}//while (BinSize2<=size) crospond to total buffer
try1:Tree_Result1->Print();
	Tree_Result1->Write();
	Tree_Result2->Write();
	Tree_Result3->Write();
	Tree_Result4->Write();
	Tree_Result5->Write();
	Tree_Result6->Write();
	Tree_Result7->Write();
	Tree_Result8->Write();

	f.Close();
	exit(0);
}