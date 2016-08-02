class PhysicsEngine
{
public:
    
    ~PhysicsEngine()
    {
        PhysicsSDK->Release();
    }

    static PhysicsEngine Instance()
    {
        return PhysicsEngine instance;
    };
    
    bool Initialize()
    {
        PhysicsSDK = physx::PxCreatePhysics(PX_PHYSICS_VERSION, gDefaultAllocatorCallback, gDefaultErrorCallback, PxTolerancesScale() );
        if(PhysicsSDK == NULL) 
        {
            return false;
        }
        
        if (!PxInitExtensions(PhysicsSDK))
        {
            cerr<< "PxInitExtensions failed!" <<endl;
            return false;
        }
        
    #ifdef _DEBUG
        PxExtensionVisualDebugger::connect(PhysicsSDK->getPvdConnectionManager(),"localhost",5425, 10000, true);
    #endif


        return true;
    };
    
    physx::PxSceneDesc CreateScene()
    {
        
    };
protected:
    std::shared_ptr<physx::PxPhysics> PhysicsSDK;
};

class Physical
{
    
}