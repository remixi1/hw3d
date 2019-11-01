cbuffer LightCBuf
{
	float3 lightPos;
    
    float3 ambient ;
    float3 diffuseColor ;
    float diffuseIntensity ;
    float attConst ;
    float attLin ;
    float attQuad ;
};

cbuffer ObjectCBuf
{
    float3 materialColor;
};

float4 main(float3 worldPos : Position, float3 n : Normal) : SV_Target
{

	const float3 vTol = lightPos - worldPos;
	const float distTol = length(vTol);
	const float3 dirTol = vTol / distTol;

    const float att = 1.0f / (attConst + attLin * distTol + attQuad * (distTol * distTol));
    const float3 diffuse = diffuseColor * diffuseIntensity * att * max(0.0f, dot(dirTol, n));
    return float4(saturate((diffuse + ambient) * materialColor), 1.0f);
}