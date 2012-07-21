Option Explicit
Dim FACE : set FACE=createobject( "FACElib_100.FACE")


    ' FACE Begin
    FACE.Logging ' Log make

    ' フォームを作る
    FACE.wDefault "FACE Test Application 波形処理データ"
    ' サウンドミキシングモード
    ' ネットよりダウンロードしてチャンネル１へロード
    FACE.Download "http://crenbox.s31.xrea.com/Sure.mp3", "EveryLittleThing-Sure.mp3"
    FACE.Snd_Open 1, "EveryLittleThing-Sure.mp3"
    FACE.Snd_LoopPlay 1
    
    ' 画像保持用スプライトを作成し、黒で塗りつぶし
    FACE.SpriteState 1, True
    FACE.DrawBox 0, 0, 640, 480, 0, True
    FACE.DrawBox 0, 0, 640, 480, 0, True, 1

    ' 変数定義
    Dim lD , D , x, CH1  , CH2
    CH1 = 0: CH2 = 0: x = 0
    Do
        ' 音データ取得
        D = FACE.Snd_GetData(1)
        ' 波を描く
        FACE.DrawLine x - 1, lD + 240, x, D + 240, 1, &HFF: lD = D ' 保持

        ' 画面はしまできたらスクロール開始
        If x < 600 Then
            x = x + 1
        Else
            FACE.Blt 0, 1, 0, 640, 480, 1, 0, 0
            FACE.SpriteCopy 1, 0
        End If
        
        ' ボックス
        If D > 0 Then
            CH1 = CH1 - Sgn(CH1 - Abs(D) * 15)
        ElseIf D < 0 Then
            CH2 = CH2 - Sgn(CH2 - Abs(D) * 15)
        End If
        FACE.DrawBox 0, 0, 640, 20, 0, True
        FACE.DrawBox 0, 0, CH1, 10, &HFFFF, True
        FACE.DrawBox 0, 10, CH2, 10, &HFFFF, True
        FACE.Refresh
        ' リフューズ
        If FACE.DoEvents Then Exit Do
    Loop
    
	set FACE=nothing
