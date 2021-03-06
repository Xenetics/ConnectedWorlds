#include "MathUtils.h"
#include <math.h>
#include <DirectXMath.h>

using namespace DirectX;


Vec2& VectorMath::Normalize(const Vec2* vec)
{
	Vec2 retval;
	XMVECTOR xmVec = XMLoadFloat2((XMFLOAT2*)vec);
	xmVec = XMVector2Normalize(xmVec);
	XMStoreFloat2((XMFLOAT2*)&retval, xmVec);
	return retval;
}

float VectorMath::Magnitude(const Vec2* vec)
{
	XMVECTOR xmVec = XMLoadFloat2((XMFLOAT2*)vec);
	return XMVector2Length(xmVec).m128_f32[0];
}
