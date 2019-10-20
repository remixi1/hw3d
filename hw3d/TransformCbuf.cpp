#include "TransformCbuf.h"


TransformCbuf::TransformCbuf(Graphics& gfx,const Drawable& parent)
	:
	vcbuf(gfx),
	parent(parent)
{}
void TransformCbuf::Bind(Graphics& gfx) noexcept
{
	vcbuf.update(gfx,
		DirectX::XMMatrixTranspose(
			parent.GetTransformXM() * gfx.GetProjection()
		)
	);
	vcbuf.Bind(gfx);
}