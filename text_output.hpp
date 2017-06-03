#include <fstream>
#include <shlobj.h>
#include <string>


enum 
{
  DESKTOP
};

#ifndef __TEXTOUTPRINT_H_
#define __TEXTOUTPRINT_H_



class TextOutput{
public:

	//�R���X�g���N�^
	TextOutput();
	//�f�X�g���N�^
	~TextOutput();

	//����:(�^�C�g��,�{��)
	void WriteText(std::string,std::string);
	//����:(�^�C�g��,�{��,�p�X)
	void WriteText(std::string, std::string , int);

private:

	//�f�X�N�g�b�v�̃p�X���擾
	std::string getDeskPath();
	//�g���q���w�肳��Ă��Ȃ���Βǉ�
	std::string addExtension(std::string);

};
#endif