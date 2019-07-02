#include "stdafx.h"
#include "Window.h"
#include "Pen.h"

Window::Window()
{

}
Window::~Window()
{
	DeleteGO(m_skinModelRender);
}

bool Window::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/ste/S_mado.cmo");
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetScale(m_scale);
	m_skinModelRender->SetRotation(m_rotation);

	// CPhysicsStaticObjectÇÃèâä˙âª
	m_physicsStaticObject.CreateMesh(m_position, CQuaternion::Identity, m_scale, m_skinModelRender);

	return true;
}
void Window::Update()
{

	QueryGOs<Pen>("pen", [&](Pen* pen) {
		CVector3 pen_position = pen->Getm_Position();
		CVector3 diff = pen_position - m_position;
		if (diff.Length() < 100.0f) {
			//åÇÇΩÇÍÇΩ....
			//ÉyÉìÇ‡è¡Ç¶ÇÎ
			pen->SetDeath();
			DeleteGO(this);
		}
		return true;
		});



	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetScale(m_scale);
	m_skinModelRender->SetRotation(m_rotation);

}

