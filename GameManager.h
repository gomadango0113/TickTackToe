#pragma once

enum GameStatus {
	WAITING, //�Q�[���J�n�ҋ@��
	RUNNING, //�Q�[����
	ENDING //�Q�[���I���ς�
};

extern int timer; //���݂̎���
extern GameStatus status; //�Q�[���̏��

void initGame(); //�Q�[��������������֐�