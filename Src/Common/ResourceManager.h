#pragma once

#include <memory>
#include <map>
#include <string>
#include "Resource.h"

class ResourceManager
{

public:

	//�g�p���镡�����̉摜�i�A�j���[�V�����j�Ȃǂ̒萔�o�^

	static constexpr int CHARACTER_ORIGIN_SIZE_X = 96;
	static constexpr int CHARACTER_ORIGIN_SIZE_Y_2 = 256;

	// ���\�[�X��
	enum class SRC
	{
		//�摜
		MAP_TILE,
		//�L�����N�^�[
		CHARACTER_1,
		CHARACTER_2,
		CHARACTER_3,
		CHARACTER_4,
		CHARACTER_5,
		CHARACTER_6,
		CHARACTER_7,
		CHARACTER_8,
		CHARACTER_9,
		CHARACTER_10,
		CHARACTER_11,
		CHARACTER_12,
		CHARACTER_13,
		CHARACTER_14,
		CHARACTER_15,
		CHARACTER_16,
		CHARACTER_17,
		CHARACTER_18,
		CHARACTER_19,
		CHARACTER_20,
		CHARACTER_21,
		CHARACTER_22,
		CHARACTER_23,
		CHARACTER_24,
		CHARACTER_25,
		CHARACTER_26,
		CHARACTER_27,
		CHARACTER_28,
		CHARACTER_29,
		CHARACTER_30,
		CHARACTER_31,
		CHARACTER_32,

		//CSV
		STAGE,

		//���ʉ�
		
		//BGM
		
		//�G�t�F�N�g
	};

	// �����I�ɃC���X�e���X�𐶐�����
	static void CreateInstance(void);

	// �ÓI�C���X�^���X�̎擾
	static ResourceManager& GetInstance(void);

	// ������
	void Init(void);

	// ���(�V�[���ؑ֎��Ɉ�U���)
	void Release(void);

	// ���\�[�X�̊��S�j��
	void Destroy(void);

	// ���\�[�X�̃��[�h
	const Resource& Load(SRC src);

	// ���\�[�X�̕������[�h(���f���p)
	int LoadModelDuplicate(SRC src);

private:

	// �ÓI�C���X�^���X
	static ResourceManager* instance_;

	//���o�^
	Resource unregistered;

	// ���\�[�X�Ǘ��̑Ώ�
	std::map<SRC, std::unique_ptr<Resource>> resourcesMap_;
	//std::map<SRC, Resource> resourcesMap_;
	 
	
	// �ǂݍ��ݍς݃��\�[�X
	std::map<SRC, Resource&> loadedMap_;
	//std::map<SRC, Resource*> loadedMap_;

	// �f�t�H���g�R���X�g���N�^��private�ɂ��āA
	// �O�����琶���ł��Ȃ��l�ɂ���
	ResourceManager(void);

	// �f�X�g���N�^�����l
	~ResourceManager(void) = default;

	// �������[�h
	Resource& _Load(SRC src);

};

