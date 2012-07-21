Attribute VB_Name = "Module1"
Option Explicit

Sub Main()


Dim FACE
Set FACE = CreateObject("FACE")

With FACE
    .Logging
    .wDefault ("FACELlib - WaveAnalyzer")
    .SoftwareFPS = 200
    .Snd_Open 1, "2.“V‘ÌŠÏ‘ª.wav"
    .Snd_LoopPlay 1, 1
    
    Dim Dat, OldDat, x
    Dim CH1, CH2
    Dat = 0: OldDat = 0: x = 0: CH1 = 0: CH2 = 0
    
    Do
        Dat = .Snd_GetData(1)
        x = x + 1
        If x > 640 Then x = 0
        .DrawLine x + 2, 0, x + 2, 480, &H0
        .DrawLine x, OldDat + 240, x + 1, Dat + 240, &HFF
        OldDat = Dat
        If Dat > 0 Then
            CH1 = CH1 - Sgn(CH1 - Abs(Dat) * 6)
        End If
        If Dat < 0 Then
            CH2 = CH2 - Sgn(CH2 - Abs(Dat) * 6)
        End If
        .DSetFillStyle -1
        .DrawBox 0, 0, 640, 60, 0, True
        .DSetFillStyle 4
        .DrawBox 0, 0, CH1, 10, &HFFFFFF, True
        .DrawBox 0, 10, CH2, 10, &HFFFFFF, True
        .Refresh
        If .DoEvents Then Exit Do
    Loop
End With
Set FACE = Nothing
End Sub
