#include "zPlot.h"

ClassImp(zPlot);

zPlot::zPlot()
{
  analysisTitle = "Test Analysis";
  outfileName = "test.root";
  clearHistVectors();
  makeFrontPage();
}

zPlot::zPlot(TString anaTitle, TString outName)
{
  analysisTitle = anaTitle;
  outfileName = outName;
  clearHistVectors();
  makeFrontPage();
}

zPlot::~zPlot()
{
}

void zPlot::clearHistVectors()
{
  th1.clear();
  th2.clear();
  th3.clear();
  tgraph.clear();
  tcanvas.clear();
}

void zPlot::addTH1(TString name, TString title, int xBins, int xLow, int xHigh)
{
  th1.push_back(new TH1F(name, title, xBins, xLow, xHigh));
}

void zPlot::addTH1(TH1* h)
{
  th1.push_back(h);
}

void zPlot::addTH2(TString name, TString title, int xBins, int xLow, int xHigh,int yBins, int yLow, int yHigh)
{
  th2.push_back(new TH2F(name, title, xBins, xLow, xHigh, yBins, yLow, yHigh));
}

void zPlot::addTH2(TH2* h)
{
  th2.push_back(h);
}

void zPlot::addTH3(TString name, TString title, int xBins, int xLow, int xHigh,int yBins, int yLow, int yHigh, int zBins, int zLow, int zHigh)
{
  th3.push_back(new TH3F(name, title, xBins, xLow, xHigh, yBins, yLow, yHigh, zBins, zLow, zHigh));
}

void zPlot::addTH3(TH3* h)
{
  th3.push_back(h);
}

void zPlot::addCanvas(TString name, TString title)
{
  tcanvas.push_back(new TCanvas(name,title,50,50,1050,1050));
}

void zPlot::plotTH1(TString name, TCanvas* c, int i=0, TString opt="pe")
{
  TH1* h = getTH1(name);
  if(!i)
    c->cd();
  else
    c->cd(i);
  h->Draw(opt);
}

void zPlot::plotTH2(TString name, TCanvas* c, int i=0, TString opt="pe")
{
  TH2* h = getTH2(name);
  if(!i)
    c->cd();
  else
    c->cd(i);
  h->Draw(opt);
}

void zPlot::plotTH3(TString name, TCanvas* c, int i=0, TString opt="")
{
  TH3* h = getTH3(name);
  if(!i)
    c->cd();
  else
    c->cd(i);
  h->Draw(opt);
}

TH1* zPlot::getTH1(TString name)
{
  TH1* junk = new TH1F();
  for(int i=0;i<th1.size();i++)
  {
    if(name == th1[i]->GetName())
      return th1[i];
  }
  cout << name << " not found in th1 vector.";
  return junk;
}

TH2* zPlot::getTH2(TString name)
{
  TH2* junk = new TH2F();
  for(int i=0;i<th1.size();i++)
  {
    if(name == th2[i]->GetName())
      return th2[i];
  }
  cout << name << " not found in th2 vector.";
  return junk;
}

TH3* zPlot::getTH3(TString name)
{
  TH3* junk = new TH3F();
  for(int i=0;i<th3.size();i++)
  {
    if(name == th3[i]->GetName())
      return th3[i];
  }
  cout << name << " not found in th3 vector.";
  return junk;
}

TCanvas* zPlot::getCanvas(TString name)
{
  TCanvas* junk = new TCanvas();
  for(int i=0;i<tcanvas.size();i++)
  {
    if(name == tcanvas[i]->GetName())
      return tcanvas[i];
  }
  cout << name << " not found in tcanvas vector.";
  return junk;
}

TGraph* zPlot::getTGraph(TString name)
{
  TGraph* junk = new TGraph();
  for(int i=0;i<tgraph.size();i++)
  {
    if(name == tgraph[i]->GetName())
      return tgraph[i];
  }
  cout << name << " not found in tgraph vector.";
  return junk;
}

void zPlot::fillTH1(TString name, float val, float weight=1)
{
  getTH1(name)->Fill(val,weight);
}
void zPlot::fillTH2(TString name, float val, float val2, float weight=1)
{
  getTH2(name)->Fill(val,val2,weight);
}
void zPlot::fillTH3(TString name, float val, float val2, float val3, float weight=1)
{
  getTH3(name)->Fill(val,val2,val3,weight);
}

void zPlot::prettyTGraph(TGraphErrors* h, int col, int style, float yrangeLow, float yrangeHigh)
{
  h->GetYaxis()->SetRangeUser(yrangeLow,yrangeHigh);
  h->SetMarkerColor(col);
  h->SetLineColor(col);
  h->SetMarkerStyle(style);
  h->SetMarkerSize(1.2);
}

void zPlot::prettyTGraph(TGraph* h, int col, int style, float yrangeLow, float yrangeHigh)
{
  h->GetYaxis()->SetRangeUser(yrangeLow,yrangeHigh);
  h->SetMarkerColor(col);
  h->SetLineColor(col);
  h->SetMarkerStyle(style);
  h->SetMarkerSize(1.2);
}

void zPlot::pretty1DHist(TString name, int col, int style)
{
  TH1* h = getTH1(name);
  h->SetMarkerColor(col);
  h->SetLineColor(col);
  h->SetMarkerStyle(style);
  h->SetMarkerSize(1.2);
}

void zPlot::pretty1DHistFill(TString name, int col, int style)
{
  TH1* h = getTH1(name);
  h->SetLineColor(kBlack);
  h->SetMarkerStyle();
  h->SetFillStyle(style);
  h->SetFillColor(col);
}

void zPlot::makeFrontPage()
{
  //Set front page
  TCanvas* fp = new TCanvas("fp","Front Page",100,0,1000,900);
  fp->cd();
  TBox *bLabel = new TBox(0.01, 0.88, 0.99, 0.99);
  bLabel->SetFillColor(38);
  bLabel->Draw();
  TLatex tl;
  tl.SetNDC();
  tl.SetTextColor(kWhite);
  tl.SetTextSize(0.033);
  char tlName[100];
  char tlName2[100];

  TString titlename = outfileName;
  int found = titlename.Last('/');
  if(found >= 0){
    titlename.Replace(0, found+1, "");
  } 
  tl.SetTextSize(0.05);
  tl.SetTextColor(kWhite);
  tl.DrawLatex(0.05, 0.92,analysisTitle);

  TBox *bFoot = new TBox(0.01, 0.01, 0.99, 0.12);
  bFoot->SetFillColor(38);
  bFoot->Draw();
  tl.SetTextColor(kWhite);
  tl.SetTextSize(0.05);
  tl.DrawLatex(0.05, 0.05, (new TDatime())->AsString());
  tl.SetTextColor(kBlack);
  tl.SetTextSize(0.03);
  tl.DrawLatex(0.1, 0.14, titlename);

  tcanvas.push_back(fp);
}

void zPlot::makePDF()
{
  char filename[100];
  sprintf(filename,"%s", outfileName.Data());
  TCanvas* temp = new TCanvas();
  char name[100];
  sprintf(name, "%s.pdf[", filename);
  temp->Print(name);
  sprintf(name, "%s.pdf", filename);
  for(int i=0; i<tcanvas.size(); i++)
  {
    tcanvas[i]->Print(name);
  }
  sprintf(name, "%s.pdf]", filename);
  temp->Print(name);
}
