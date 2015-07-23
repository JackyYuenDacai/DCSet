#include"DCDNodeT.h"
typedef unsigned char   uchar;
typedef unsigned long long ullong;
class DCAtomCollection
{
	enum DefType
	{
	Unknown=0,
	Hydiogen,
	Helium,
	Lithium,
	Beryllium,
	Boron,
	Carbon,
	Nitrogen,
	Oxygen,
	Fluorine,
	Neon,
	Sodium,
	Magnesium,
	Aluminium,
	Silicon,
	Phosphorus,
	Sulfur,
	Chlorine,
	Argon,
	Potassium,
	Calcium,
	Scandium,
	Titanium,
	Vanadium,
	Chromium,
	Manganes,
	Iron,
	Cobaly,
	Nickel,
	coppe,
	Zinc,
	Galliun,
	Germanium,
	Arsenic,
	Selenium,
	Bromine,
	Krypton,
	Rubidium,
	Strontium,
	Yttrium,
	Zirconium,
	Niobium,
	Molybdenum,
	Technetium,
	Rhodium,
	Palladium,
	Silver,
	Cadmium,
	Indium,
	Tin,
	Antimony,
	Tellurium,
	Lodine,
	Xenon,
	Caesium,
	Barium,
	Lanthanum,
	Cerium,
	Praseodymium,
	Neodymium,
	Promethium,
	Samarium,
	Europium,
	Gadolinium,
	Terbium,
	Dysprosium,
	Holmium,
	Erbium,
	Thulium,
	Ytterbium,
	Lutetium,
	Hafnium,
	Tantalum,
	Tungsten,
	Rhenium,
	Osmium,
	Iridium,
	Platinum,
	Gold,
	Mercury,
	Thallium,
	Lead,
	Bismuth,
	Polonium,
	Astatine,
	Radon,
	Francium,
	Radium,
	Actinium,
	Thorium,
	Protactinium,
	Uranium,
	Neptunium,
	Plutonium,
	Americium,
	Curium,
	Berkelium,
	Californium,
	Einsteinium,
	Fermium,
	Mendelevium,
	Nobelium,
	Lawrencium,
	Rutherfordium,
	Dubnium,
	Seaborgium,
	Bohrium,
	Hassium,
	Meltnerium,
	Darmstadtium,
	Roentgenium,
	Copernicium,
	Ununtrium,
	Flerovium,
	Ununpentium,
	Livermorium,
	Ununseptium,
	Ununoctium,
	TableTop
	};
	struct SubSetInfo
	{
		char*Name;
		float AtomMass;
		uchar State;
		float bpoint;
		float mpoint;
		
	};	
	ullong TypeCount;
	struct Link
	{
		Atom*Ptr[2];
		uchar LinkLine;
	};	
	struct Atom
	{
		ullong      Id;
		ullong  TypeId;
		ullong LocalId;
		bool Info;
		SubSetInfo info;
		ullong LinkCount;
		DCDNode<Link*> LinkPtr;
	};	
	DCDNode<Atom*> Vector;
	DCDNode<Atom*> TypeVector;
	DCDNode<int> IdVector;
	ullong TomCount;
	
public:
	DCAtomCollection()
	{
		Vector.Settle();
		TypeVector.Settle();
		IdVector.Settle();
		TomCount=0;
		IdVector[0]=0;
	}
	bool IsIdExsist(ullong Id,ullong LocalId=0)
	{
		for(ullong i=0;i<TomCount;i++)
		if(Vector[i]->Id==Id&&Vector[i]->LocalId==LocalId)
		return true;		
		return false;
	}
	bool IsTypeExsist(ullong TypeId)
	{
		for(ullong i=0;i<IdVector.GetLength();i++)
		{
			if(TypeId==IdVector[i])
			return true;
		}
		if(TypeId>=TableTop)
		return false;
		return true;
	}
	bool AddAtom(ullong TypeId)
	{
		if(!IsTypeExsist(TypeId))
		return false;
		Atom*addbuf=(Atom*)malloc(sizeof(Atom));
		addbuf->Id=TomCount;
		addbuf->TypeId=TypeId;
		addbuf->LocalId=0;
		addbuf->LinkCount=0;
		bool Info=false;
		TomCount++;
		return true;
		
	}
	bool LinkAtom(ullong AlfId,ullong BryId)
	{
		Link*linkbuf=(Link*)malloc(sizeof(Link));
		linkbuf->Ptr=
		Vector[AlfId]->LinkPtr[Vector[AlfId]->LinkCount]=linkbuf;
	}
	~DCAtomCollection()
	{
		//for(int i=0;i<Vector.GetLength();i++)
		//Vector[i]->LinkPtr.DelAll(),Vector[i]->LinkPtr.ClearArray(),free(Vector[i]);
	}
	
};
