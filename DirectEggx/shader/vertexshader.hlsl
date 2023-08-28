struct VS_INPUT
{
    float2 inPos : POSITION;
    float4 inColour : COLOUR;
};

struct VS_OUTPUT
{
    float4 outPosition : SV_POSITION;
    float4 outColour : COLOUR;
};

VS_OUTPUT main(VS_INPUT input)
{
    VS_OUTPUT output;
    output.outPosition = float4(input.inPos, 0.0f, 1.0f);
    output.outColour = input.inColour;
    
    return output;
}