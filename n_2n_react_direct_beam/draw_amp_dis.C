#ifndef __CINT__
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <TFile.h>
#include <TH1.h>
#include <TTree.h>
#include <TRandom.h>
#include <TCanvas.h>
#include <stdlib.h>
#endif

using namespace std;

void draw_amp_dis()
{
	TString root_file_location="G:\\project\\n_2n_exp_direct_beam\\origin_data\\120\\";
	TString output_file_location="G:\\project\\n_2n_exp_direct_beam\\final_data\\120\\";
	
   TFile *f = new TFile(root_file_location + "test_0120.root");
   TTree *Tree_Result1 = (TTree*)f->Get("Tree_Result1");
   TTree *Tree_Result2 = (TTree*)f->Get("Tree_Result2");
   TTree *Tree_Result3 = (TTree*)f->Get("Tree_Result3");
   TTree *Tree_Result4 = (TTree*)f->Get("Tree_Result4");
   TTree *Tree_Result5 = (TTree*)f->Get("Tree_Result5");
   TTree *Tree_Result6 = (TTree*)f->Get("Tree_Result6");
   TTree *Tree_Result7 = (TTree*)f->Get("Tree_Result7"); 
   TTree *Tree_Result8 = (TTree*)f->Get("Tree_Result8");

   Tree_Result1->Draw("N_CHAN_ENERGY_1>>hist_adc_1(1e4,0,1e5)");
   Tree_Result2->Draw("N_CHAN_ENERGY_2>>hist_adc_2(2e3,0,2e4)");
   Tree_Result3->Draw("N_CHAN_ENERGY_3>>hist_adc_3(2e3,0,2e4)");
   Tree_Result4->Draw("N_CHAN_ENERGY_4>>hist_adc_4(2e3,0,2e4)");
   Tree_Result5->Draw("N_CHAN_ENERGY_5>>hist_adc_5(2e3,0,2e4)");
   Tree_Result6->Draw("N_CHAN_ENERGY_6>>hist_adc_6(2e3,0,2e4)");
   Tree_Result7->Draw("N_CHAN_ENERGY_7>>hist_adc_7(2e3,0,2e4)");
   Tree_Result8->Draw("N_CHAN_ENERGY_8>>hist_adc_8(2e3,0,2e4)");

   TString mark[8];
   
   mark[0] = "logical_signal";
   mark[1] = "detector_section_1";
   mark[2] = "detector_section_2";
   mark[3] = "detector_section_3";
   mark[4] = "detector_section_4";
   mark[5] = "detector_section_5";
   mark[6] = "detector_section_6";
   mark[7] = "detector_section_7";

	TString sample_name[1];
	sample_name[0] = "#bullet Sample: null";

   TH1F *hist_adc_1 = (TH1F*)gDirectory->Get("hist_adc_1");
   TH1F *hist_adc_2 = (TH1F*)gDirectory->Get("hist_adc_2");
   TH1F *hist_adc_3 = (TH1F*)gDirectory->Get("hist_adc_3");
   TH1F *hist_adc_4 = (TH1F*)gDirectory->Get("hist_adc_4");
   TH1F *hist_adc_5 = (TH1F*)gDirectory->Get("hist_adc_5");
   TH1F *hist_adc_6 = (TH1F*)gDirectory->Get("hist_adc_6");
   TH1F *hist_adc_7 = (TH1F*)gDirectory->Get("hist_adc_7");
   TH1F *hist_adc_8 = (TH1F*)gDirectory->Get("hist_adc_8");


    TCanvas* c2;
   c2 = new TCanvas( "c2", "c2", 1600, 900 );
   c2->Divide(2,4);

   c2->cd(1);
   format_plot_1(hist_adc_1,mark[0],sample_name[0]);
   c2->cd(2);
   format_plot_2(hist_adc_2,mark[1]);
   c2->cd(3);
   format_plot_2(hist_adc_3,mark[2]);
   c2->cd(4);
   format_plot_2(hist_adc_4,mark[3]);
   c2->cd(5);
   format_plot_2(hist_adc_5,mark[4]);
   c2->cd(6);
   format_plot_2(hist_adc_6,mark[5]);
   c2->cd(7);
   format_plot_2(hist_adc_7,mark[6]);
   c2->cd(8);
   format_plot_2(hist_adc_8,mark[7]);

   c2->SaveAs( output_file_location + "amplitude_distribution.pdf" );
   c2->SaveAs( output_file_location + "amplitude_distribution.eps" );

}
