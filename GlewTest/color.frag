#version 330

in vec3 vPosition;
in vec3 vColor;
in vec3 vNormal;

out vec4 outputF;

void main()
{
	vec3 lightSource = vec3(100.0, 50.0, 20.0);
	vec3 lightDirection = normalize(lightSource);

	vec3 normal = normalize(vNormal);
	float ambient = 0.2;
	float diffuse = max(0.0, dot(lightDirection, normal));
	float spec = 0.0;
	if (diffuse > 0.0) {
		spec = pow(max(0.0, dot(normalize(lightSource - vPosition), normal)), 10);
	}

	outputF = vec4(vColor * (ambient + diffuse * 0.7), 1.0) + vec4(1.0, 1.0, 1.0, 1.0) * spec * 0.3;
}