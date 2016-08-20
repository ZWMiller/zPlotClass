#include "zPlot.h"
#include "zPlot.cxx"

void testHist()
{
  zPlot* zP = new zPlot("Analysis Test","testFile");
  zP->addTH1("test","Random Test;x;y",1000,-1,1);
  zP->addTH2("2Dtest","Random Test;x;y",1000,-1,1,1000,-1,1);
  zP->addCanvas("can","test");
  zP->addCanvas("2dcan","test2d");
  zP->getCanvas("can")->Divide(1,2);

  gRandom->SetSeed();
  float x;
  float y;
  for(int i=0; i<10000; i++)
  {
    x = gRandom->Gaus(0,0.3);
    y = gRandom->Gaus(0,0.3);
    zP->fillTH1("test",x);
    zP->fillTH2("2Dtest",x,y);
  }

  zP->pretty1DHist("test",zP->colors[0],20);
  zP->plotTH1("test","can",1);
  zP->getTH1("test")->Fit("gaus");
  zP->plotTH2("2Dtest","can",2);
  zP->plotTH2("2Dtest","2dcan");
  zP->makePDF();
  zP->saveAllHists("testFolder2");
}
