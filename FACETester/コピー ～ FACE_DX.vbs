Option Explicit
Dim FACE : set FACE=createobject( "FACElib_100.FACE")


    ' FACE Begin
    FACE.Logging ' Log make

    ' �t�H�[�������
    FACE.wDefault "FACE Test Application �g�`�����f�[�^"
    ' �T�E���h�~�L�V���O���[�h
    ' �l�b�g���_�E�����[�h���ă`�����l���P�փ��[�h
    FACE.Download "http://crenbox.s31.xrea.com/Sure.mp3", "EveryLittleThing-Sure.mp3"
    FACE.Snd_Open 1, "EveryLittleThing-Sure.mp3"
    FACE.Snd_LoopPlay 1
    
    ' �摜�ێ��p�X�v���C�g���쐬���A���œh��Ԃ�
    FACE.SpriteState 1, True
    FACE.DrawBox 0, 0, 640, 480, 0, True
    FACE.DrawBox 0, 0, 640, 480, 0, True, 1

    ' �ϐ���`
    Dim lD , D , x, CH1  , CH2
    CH1 = 0: CH2 = 0: x = 0
    Do
        ' ���f�[�^�擾
        D = FACE.Snd_GetData(1)
        ' �g��`��
        FACE.DrawLine x - 1, lD + 240, x, D + 240, 1, &HFF: lD = D ' �ێ�

        ' ��ʂ͂��܂ł�����X�N���[���J�n
        If x < 600 Then
            x = x + 1
        Else
            FACE.Blt 0, 1, 0, 640, 480, 1, 0, 0
            FACE.SpriteCopy 1, 0
        End If
        
        ' �{�b�N�X
        If D > 0 Then
            CH1 = CH1 - Sgn(CH1 - Abs(D) * 15)
        ElseIf D < 0 Then
            CH2 = CH2 - Sgn(CH2 - Abs(D) * 15)
        End If
        FACE.DrawBox 0, 0, 640, 20, 0, True
        FACE.DrawBox 0, 0, CH1, 10, &HFFFF, True
        FACE.DrawBox 0, 10, CH2, 10, &HFFFF, True
        FACE.Refresh
        ' ���t���[�Y
        If FACE.DoEvents Then Exit Do
    Loop
    
	set FACE=nothing
