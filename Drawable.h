class IRenderContext
{
    void Update(double time) = 0;	
	bool PreRender() = 0;	
    void Render() = 0;	
	void PostRender() = 0;	
}

