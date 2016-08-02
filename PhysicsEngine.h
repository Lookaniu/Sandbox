////////////////////////////////////////////////////////////////////////////////
//--- NV Phycis SDK wrapper
////////////////////////////////////////////////////////////////////////////////

using namespace physx;
using namespace std;

////////////////////////////////////////////////////////////////////////////////
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
        PhysicsSDK = PxCreatePhysics(PX_PHYSICS_VERSION, gDefaultAllocatorCallback, gDefaultErrorCallback, PxTolerancesScale() );
        if (PhysicsSDK == NULL) 
        {
            return false;
        }
        
        if (!PxInitExtensions(PhysicsSDK))
        {
            cerr << "Extensions initialisation failed!" << endl;
            return false;
        }
        
    //#ifdef _DEBUG
    //    PxExtensionVisualDebugger::connect(PhysicsSDK->getPvdConnectionManager(),"localhost",5425, 10000, true);
    //#endif


        return true;
    };
    
    PxSceneDesc CreateScene()
    {
        
    };
protected:
    shared_ptr<PxPhysics> PhysicsSDK;
};

////////////////////////////////////////////////////////////////////////////////
class Physical
{
public:
    Physical();
    
    PxShape shape;
}
////////////////////////////////////////////////////////////////////////////////