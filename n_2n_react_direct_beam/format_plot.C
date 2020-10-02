#ifndef __CINT__
#include <string>
#include <iostream>
#include <fstream>
#include <TFile.h>
#include <TH1.h>
#include <TTree.h>
#include <TCanvas.h>
#include "TAxis.h"
#include "TH1.h"
#include "TArrayD.h"
#include "TApplication.h"
#include "TLegend.h"
#include "TLatex.h"
#include "TStyle.h"
#include "TCutG.h"
#endif

using namespace std;

void format_plot_1(TH1F* H_f, TString in_file, TString sample_name){
    gStyle->SetOptStat(0);
    gPad->SetTopMargin(0.2);
    gPad->SetLeftMargin(0.2);
    gPad->SetBottomMargin(0.4);

    H_f->GetXaxis()->SetTitle("Energy (channels)");
    H_f->GetYaxis()->SetTitle("Counts (a.u.)");
    H_f->GetXaxis()->CenterTitle();
    H_f->GetYaxis()->CenterTitle();

    TH1F *H_f_c = (TH1F*)H_f->DrawClone();
    H_f_c->GetXaxis()->SetRangeUser(2000,100000);
    Float_t y_max = H_f_c->GetBinContent(H_f_c->GetMaximumBin());
    H_f_c->GetXaxis()->SetRangeUser(500,H_f_c->GetXaxis()->GetBinCenter(H_f_c->GetMaximumBin()));
    Int_t binx = H_f_c->GetMinimumBin();
    Double_t x_min = H_f_c->GetXaxis()->GetBinCenter(binx);
    cout<<"x_min = "<<x_min<<endl;
    H_f_c->GetXaxis()->SetRangeUser(x_min,20000);

    H_f->GetXaxis()->SetMaxDigits(4);
    H_f->GetYaxis()->SetMaxDigits(5);
    H_f->GetYaxis()->SetRangeUser(0,1.2*y_max);
    H_f->SetTitle("");
    H_f->GetXaxis()->SetNdivisions(510);
    H_f->GetYaxis()->SetNdivisions(4);
    H_f->GetXaxis()->SetTitleSize(15);
    H_f->GetXaxis()->SetTitleFont(43);
    H_f->GetXaxis()->SetTitleOffset(7);
    H_f->GetXaxis()->SetLabelFont(43);
    H_f->GetXaxis()->SetLabelSize(25);
    H_f->GetYaxis()->SetTitleSize(15);
    H_f->GetYaxis()->SetTitleFont(43);
    H_f->GetYaxis()->SetTitleOffset(3);
    H_f->GetYaxis()->SetLabelFont(43);
    H_f->GetYaxis()->SetLabelSize(25);
    H_f->GetXaxis()->SetTickLength(0.1);

    auto *text1 = new TLatex(0.85,0.7,in_file);
    text1->SetNDC(kTRUE);
    text1->SetTextAlign(32);
    text1->SetTextSize(0.1);
    text1->SetTextColor(2);
    auto *text2 = new TLatex(0.2,0.92,sample_name);
    text2->SetNDC(kTRUE);
    text2->SetTextAlign(32);
    text2->SetTextSize(0.1);

    H_f->Draw("hist");
    H_f_c->Draw("hist same");
    H_f_c->SetFillColor(kGreen);
    text1->Draw("same");
    text2->Draw("same");

    TLegend *legend=new TLegend(0.3,0.5,0.5,0.7);
    legend->SetFillColor(0);
    legend->SetLineColor(0);
    legend->AddEntry(H_f," total events");
    legend->AddEntry(H_f_c," neutron events");
    legend->SetTextSize(0.05);
    legend->DrawClone();
}

void format_plot_2(TH1F* H_f, TString in_file ){
    gStyle->SetOptStat(0);
    gPad->SetTopMargin(0.05);
    gPad->SetLeftMargin(0.2);
    gPad->SetBottomMargin(0.4);

    H_f->GetXaxis()->SetTitle("Energy (channels)");
    H_f->GetYaxis()->SetTitle("Counts (a.u.)");
    H_f->GetXaxis()->CenterTitle();
    H_f->GetYaxis()->CenterTitle();

    TH1F *H_f_c = (TH1F*)H_f->DrawClone();
    H_f_c->GetXaxis()->SetRangeUser(2000,20000);
    Float_t y_max = H_f_c->GetBinContent(H_f_c->GetMaximumBin());
    H_f_c->GetXaxis()->SetRangeUser(500,H_f_c->GetXaxis()->GetBinCenter(H_f_c->GetMaximumBin()));
    Int_t binx = H_f_c->GetMinimumBin();
    Double_t x_min = H_f_c->GetXaxis()->GetBinCenter(binx);
    cout<<"x_min = "<<x_min<<endl;
    H_f_c->GetXaxis()->SetRangeUser(x_min,20000);

    H_f->GetXaxis()->SetMaxDigits(4);
    H_f->GetYaxis()->SetRangeUser(0,1.2*y_max);
    H_f->SetTitle("");
    H_f->GetXaxis()->SetNdivisions(510);
    H_f->GetYaxis()->SetNdivisions(5);
    H_f->GetXaxis()->SetTitleSize(15);
    H_f->GetXaxis()->SetTitleFont(43);
    H_f->GetXaxis()->SetTitleOffset(7);
    H_f->GetXaxis()->SetLabelFont(43);
    H_f->GetXaxis()->SetLabelSize(25);
    H_f->GetYaxis()->SetTitleSize(15);
    H_f->GetYaxis()->SetTitleFont(43);
    H_f->GetYaxis()->SetTitleOffset(3);
    H_f->GetYaxis()->SetLabelFont(43);
    H_f->GetYaxis()->SetLabelSize(25);

    auto *text1 = new TLatex(0.85,0.7,in_file);
    text1->SetNDC(kTRUE);
    text1->SetTextAlign(32);
    text1->SetTextSize(0.1);
    text1->SetTextColor(2);
    H_f->Draw("hist");
    H_f_c->Draw("hist same");
    H_f_c->SetFillColor(kGreen);
    text1->Draw("same");
    H_f->GetXaxis()->SetTickLength(0.1);
}

void format_plot_3(TH1D* H_f, TString in_file, TString sample_name){
    gStyle->SetOptStat(0);
    gPad->SetTopMargin(0.2);
    gPad->SetLeftMargin(0.2);
    gPad->SetBottomMargin(0.3);

    H_f->GetXaxis()->CenterTitle();
    H_f->GetYaxis()->CenterTitle();
    H_f->GetXaxis()->SetTitle("Time interval / ms");
    H_f->GetYaxis()->SetTitle("Counts (a.u.)");


    H_f->GetYaxis()->SetMaxDigits(4);
    H_f->SetTitle("");
    H_f->GetXaxis()->SetNdivisions(510);
    H_f->GetYaxis()->SetNdivisions(5);
    H_f->GetXaxis()->SetTitleSize(15);
    H_f->GetXaxis()->SetTitleFont(43);
    H_f->GetXaxis()->SetTitleOffset(7);
    H_f->GetXaxis()->SetLabelFont(43);
    H_f->GetXaxis()->SetLabelSize(25);
    H_f->GetYaxis()->SetTitleSize(15);
    H_f->GetYaxis()->SetTitleFont(43);
    H_f->GetYaxis()->SetTitleOffset(3);
    H_f->GetYaxis()->SetLabelFont(43);
    H_f->GetYaxis()->SetLabelSize(25);

    auto *text1 = new TLatex(0.85,0.7,in_file);
    text1->SetNDC(kTRUE);
    text1->SetTextAlign(32);
    text1->SetTextSize(0.1);
    text1->SetTextColor(2);
    auto *text2 = new TLatex(0.2,0.92,sample_name);
    text2->SetNDC(kTRUE);
    text2->SetTextAlign(32);
    text2->SetTextSize(0.1);

    H_f->Draw("hist");
    text1->Draw("same");
    text2->Draw("same");
    H_f->GetXaxis()->SetTickLength(0.1);
}

void format_plot_4(TH1D* H_f, TString in_file ){
    gStyle->SetOptStat(0);
    gPad->SetTopMargin(0.05);
    gPad->SetLeftMargin(0.2);
    gPad->SetBottomMargin(0.4);
    H_f->GetXaxis()->CenterTitle();
    H_f->GetYaxis()->CenterTitle();
    H_f->GetXaxis()->SetTitle("Time interval / ms");
    H_f->GetYaxis()->SetTitle("Counts (a.u.)");


    H_f->GetYaxis()->SetMaxDigits(4);
    H_f->SetTitle("");
    H_f->GetXaxis()->SetNdivisions(510);
    H_f->GetYaxis()->SetNdivisions(5);
    H_f->GetXaxis()->SetTitleSize(15);
    H_f->GetXaxis()->SetTitleFont(43);
    H_f->GetXaxis()->SetTitleOffset(7);
    H_f->GetXaxis()->SetLabelFont(43);
    H_f->GetXaxis()->SetLabelSize(25);
    H_f->GetYaxis()->SetTitleSize(15);
    H_f->GetYaxis()->SetTitleFont(43);
    H_f->GetYaxis()->SetTitleOffset(3);
    H_f->GetYaxis()->SetLabelFont(43);
    H_f->GetYaxis()->SetLabelSize(25);

    auto *text1 = new TLatex(0.85,0.7,in_file);
    text1->SetNDC(kTRUE);
    text1->SetTextAlign(32);
    text1->SetTextSize(0.1);
    text1->SetTextColor(2);
    H_f->Draw("hist");
    text1->Draw("same");
    H_f->GetXaxis()->SetTickLength(0.1);
}

void format_plot_5(TH1D* H_f, TString in_file, TString sample_name, TString count_rate){
    gStyle->SetOptStat(0);
    gPad->SetTopMargin(0.2);
    gPad->SetLeftMargin(0.2);
    gPad->SetBottomMargin(0.3);
    H_f->GetXaxis()->CenterTitle();
    H_f->GetYaxis()->CenterTitle();
    H_f->GetXaxis()->SetTitle("Time / s");
    H_f->GetYaxis()->SetTitle("Count rate (s^{-1})");
    H_f->GetYaxis()->SetMaxDigits(4);
    H_f->SetTitle("");
    H_f->GetXaxis()->SetNdivisions(510);
    H_f->GetYaxis()->SetNdivisions(5);
    H_f->GetXaxis()->SetTitleSize(15);
    H_f->GetXaxis()->SetTitleFont(43);
    H_f->GetXaxis()->SetTitleOffset(7);
    H_f->GetXaxis()->SetLabelFont(43);
    H_f->GetXaxis()->SetLabelSize(25);
    H_f->GetYaxis()->SetTitleSize(15);
    H_f->GetYaxis()->SetTitleFont(43);
    H_f->GetYaxis()->SetTitleOffset(3);
    H_f->GetYaxis()->SetLabelFont(43);
    H_f->GetYaxis()->SetLabelSize(25);
    H_f->GetXaxis()->SetTickLength(0.1);

    auto *text1 = new TLatex(0.85,0.7,in_file);
    text1->SetNDC(kTRUE);
    text1->SetTextAlign(32);
    text1->SetTextSize(0.1);
    text1->SetTextColor(2);

    auto *text2 = new TLatex(0.2,0.92,sample_name);
    text2->SetNDC(kTRUE);
    text2->SetTextAlign(32);
    text2->SetTextSize(0.1);

    auto *text3 = new TLatex(0.85,0.6,count_rate);
    text3->SetNDC(kTRUE);
    text3->SetTextAlign(32);
    text3->SetTextSize(0.1);
    text3->SetTextColor(2);

    H_f->Draw("hist");
    text1->Draw("same");
    text2->Draw("same");
	text3->Draw("same");
}

void format_plot_6(TH1D* H_f, TString in_file, TString count_rate){
    gStyle->SetOptStat(0);
    gPad->SetTopMargin(0.05);
    gPad->SetLeftMargin(0.2);
    gPad->SetBottomMargin(0.4);
    H_f->GetXaxis()->CenterTitle();
    H_f->GetYaxis()->CenterTitle();
    H_f->GetXaxis()->SetTitle("Time / s");
    H_f->GetYaxis()->SetTitle("Count rate (s^{-1})");
    H_f->GetYaxis()->SetMaxDigits(4);
    H_f->SetTitle("");
    H_f->GetXaxis()->SetNdivisions(510);
    H_f->GetYaxis()->SetNdivisions(5);
    H_f->GetXaxis()->SetTitleSize(15);
    H_f->GetXaxis()->SetTitleFont(43);
    H_f->GetXaxis()->SetTitleOffset(7);
    H_f->GetXaxis()->SetLabelFont(43);
    H_f->GetXaxis()->SetLabelSize(25);
    H_f->GetYaxis()->SetTitleSize(15);
    H_f->GetYaxis()->SetTitleFont(43);
    H_f->GetYaxis()->SetTitleOffset(3);
    H_f->GetYaxis()->SetLabelFont(43);
    H_f->GetYaxis()->SetLabelSize(25);
    H_f->GetXaxis()->SetTickLength(0.1);

    auto *text1 = new TLatex(0.85,0.7,in_file);
    text1->SetNDC(kTRUE);
    text1->SetTextAlign(32);
    text1->SetTextSize(0.1);
    text1->SetTextColor(2);
    auto *text2 = new TLatex(0.85,0.6,count_rate);
    text2->SetNDC(kTRUE);
    text2->SetTextAlign(32);
    text2->SetTextSize(0.1);
    text2->SetTextColor(2);


    H_f->Draw("hist");
    text1->Draw("same");
	text2->Draw("same");
}