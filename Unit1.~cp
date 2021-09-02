//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

//short I=0;
//int rec = false;

bool ligado = 0;

//PARA O USO DA PORTA PARALELA
//Declaração dos ponteiros para função.
typedef short _stdcall (*PtrInp)(short EndPorta);
typedef void _stdcall (*PtrOut)(short EndPorta, short datum);

// PARA USO DA PORTA PARALELA
HINSTANCE hLib;     //Instância para a DLL inpout32.dll.
PtrInp inportB;     //Instância para a função Inp32().
PtrOut outportB;    //Instância para a função Out32().

//--------------o------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
//Carrega a DLL na memória.
    hLib = LoadLibrary("inpout32.dll");

    if(hLib == NULL)
    {
        ShowMessage("Erro. O arquivo inpout32.DLL não foi encontrado.");
        Application->Terminate();
    }

    //Obtém o endereço da função Inp32 contida na DLL.
    inportB = (PtrInp) GetProcAddress(hLib, "Inp32");
    if(inportB == NULL)
    {
        ShowMessage("Erro. Erro ao endereçar a função Inp32.");
        Application->Terminate();
    }

    //Obtém o endereço da função Out32 contida na DLL.
    outportB = (PtrOut) GetProcAddress(hLib, "Out32");
    if(outportB == NULL)
    {
        ShowMessage("Erro. Erro ao endereçar a função Out32.");
        Application->Terminate();
    }

     Timer1->Enabled = false;
     KeyPreview = true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
    outportB(0x378,0);
    FreeLibrary(hLib);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BtnLigaTimerClick(TObject *Sender)
{
 Timer1->Enabled = true;
 Timer1->Interval = 800;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::BtnDesligaTimerClick(TObject *Sender)
{
 Timer1->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    if(ligado)
    {
        outportB(0x378,0);
        ligado = false;
    }
    else if(!ligado)
    {
        outportB(0x378,1);
        ligado = true;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BtnligaLEDClick(TObject *Sender)
{
        outportB(0x378,3);
        ligado = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BtnDesligaLEDClick(TObject *Sender)
{
        outportB(0x378,2);
        ligado = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BtnTimerRapidoClick(TObject *Sender)
{

   /* if(Timer1->Interval > 200)
        Timer1->Interval -= 200;    */

   Timer1->Interval = 100;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BtnTimerDevagarClick(TObject *Sender)
{
   /* if(Timer1->Interval < 2000)
        Timer1->Interval += 200;   */
   Timer1->Interval = 1400;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
Label1->Caption = AnsiString(Timer1->Interval);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    switch(Key)
    {
        case 'A':
            outportB(0x378,1);
            ligado = true;
            break;
        case 'B':
            outportB(0x378,0);
            ligado = false;
            break;
    }
}
//---------------------------------------------------------------------------
