cbuffer LightCbuf
{
    float3 lightPos;
    float3 ambient;
    float3 diffuseColor;
    float diffuseIntensity;
    float attConst;
    float attLin;
    float attQuad;
};
cbuffer ObjectCBuf
{
    float3 materialColors[6];
    float padding;
    float specularIntensity;
    float specularPower;
};


float4 main(float3 worldPos : Position, float3 n : Normal, uint tid : SV_PrimitiveID) : SV_Target
{
    const float3 vTol = lightPos - worldPos;
    const float distTol = length(vTol);
    const float3 dirtol = vTol / distTol;


    const float att = 1.0f / (attConst + attLin * distTol + attQuad * (distTol * distTol));

    const float3 diffuse = diffuseColor * diffuseIntensity * att * max(0.0f, dot(dirtol, n));

    const float w = n * dot(vTol, n);

    const float r = w * 2.0f - vTol;

    const float3 specular = att * (diffuseColor * diffuseIntensity) * specularIntensity * pow(max(0.0f, dot(normalize(-r), normalize(worldPos))), specularPower);

    return float4(saturate((diffuse + ambient + specular) * materialColors[(tid / 2) % 6]), 1.0f);

}