//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TButton *BtnLigaTimer;
    TButton *BtnDesligaTimer;
    TTimer *Timer1;
    TButton *BtnligaLED;
    TButton *BtnDesligaLED;
    TButton *BtnTimerRapido;
    TButton *BtnTimerDevagar;
    TLabel *Label1;
    TTimer *Timer2;
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall BtnLigaTimerClick(TObject *Sender);
    void __fastcall BtnDesligaTimerClick(TObject *Sender);
    void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall BtnligaLEDClick(TObject *Sender);
    void __fastcall BtnDesligaLEDClick(TObject *Sender);
    void __fastcall BtnTimerRapidoClick(TObject *Sender);
    void __fastcall BtnTimerDevagarClick(TObject *Sender);
    void __fastcall Timer2Timer(TObject *Sender);
    void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
