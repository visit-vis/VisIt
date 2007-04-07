/*-------------------------------------------------------------------------
This software is provided 'as-is', without any express or implied warranty.
In no event will the authors be held liable for any damages arising from
the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not
   claim that you wrote the original software. If you use this software
   in a product, an acknowledgment in the product documentation would be
   appreciated but is not required.

2. Altered source versions must be plainly marked as such, and must not
   be misrepresented as being the original software.

3. This notice may not be removed or altered from any source distribution.
-------------------------------------------------------------------------*/

#ifndef CGNSLIB_H
#define CGNSLIB_H

// Added by Brad Whitlock, LLNL, to produce a DLL CGNS library.
#ifdef _WIN32
#ifdef CGNSDLL_EXPORTS
#define CGNS_API __declspec(dllexport)
#else
#define CGNS_API __declspec(dllimport)
#endif
#else
#define CGNS_API 
#endif

#define CGNS_VERSION 2400
#define CGNS_DOTVERS 2.40

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      modes for cgns file                                              *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#define MODE_READ       0
#define MODE_WRITE      1
#define MODE_CLOSED     2
#define MODE_MODIFY     3

#define CG_OK		  0
#define CG_ERROR	  1
#define CG_NODE_NOT_FOUND 2
#define CG_INCORRECT_PATH 3
#define CG_NO_INDEX_DIM   4

#define Null 0
#define UserDefined 1

#ifdef __cplusplus
extern "C" {
#endif

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *  Enumerations:  if any of this enumerations need to be modified,      *
 *	           the corresponding namelist must also be updated.      *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Dimensional Units                                                *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef enum {
	MassUnitsNull, MassUnitsUserDefined,
	Kilogram, Gram, Slug, PoundMass
} MassUnits_t;

typedef enum {
	LengthUnitsNull, LengthUnitsUserDefined,
	Meter, Centimeter, Millimeter, Foot, Inch
} LengthUnits_t;

typedef enum {
	TimeUnitsNull, TimeUnitsUserDefined, Second
} TimeUnits_t;

typedef enum {
	TemperatureUnitsNull, TemperatureUnitsUserDefined,
	Kelvin, Celcius, Rankine, Fahrenheit
} TemperatureUnits_t;

typedef enum {
	AngleUnitsNull, AngleUnitsUserDefined, Degree, Radian
} AngleUnits_t;

typedef enum {
	ElectricCurrentUnitsNull, ElectricCurrentUnitsUserDefined,
	Ampere, Abampere, Statampere, Edison, auCurrent
} ElectricCurrentUnits_t;

typedef enum {
	SubstanceAmountUnitsNull, SubstanceAmountUnitsUserDefined,
	Mole, Entities, StandardCubicFoot, StandardCubicMeter
} SubstanceAmountUnits_t;

typedef enum {
	LuminousIntensityUnitsNull, LuminousIntensityUnitsUserDefined,
	Candela, Candle, Carcel, Hefner, Violle
} LuminousIntensityUnits_t;

#define NofValidMassUnits              6
#define NofValidLengthUnits            7
#define NofValidTimeUnits              3
#define NofValidTemperatureUnits       6
#define NofValidAngleUnits             4
#define NofValidElectricCurrentUnits   7
#define NofValidSubstanceAmountUnits   6
#define NofValidLuminousIntensityUnits 7

extern char const * MassUnitsName[NofValidMassUnits];
extern char const * LengthUnitsName[NofValidLengthUnits];
extern char const * TimeUnitsName[NofValidTimeUnits];
extern char const * TemperatureUnitsName[NofValidTemperatureUnits];
extern char const * AngleUnitsName[NofValidAngleUnits];
extern char const * ElectricCurrentUnitsName[NofValidElectricCurrentUnits];
extern char const * SubstanceAmountUnitsName[NofValidSubstanceAmountUnits];
extern char const * LuminousIntensityUnitsName[NofValidLuminousIntensityUnits];

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Data Class                                                       *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef enum {
	DataClassNull, DataClassUserDefined,
	Dimensional, NormalizedByDimensional,
	NormalizedByUnknownDimensional,
	NondimensionalParameter, DimensionlessConstant
} DataClass_t;
#define NofValidDataClass 7
extern char const * DataClassName[NofValidDataClass];

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *	Grid Location
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef enum {
	GridLocationNull, GridLocationUserDefined,
        Vertex, CellCenter, FaceCenter,
        IFaceCenter, JFaceCenter, KFaceCenter, EdgeCenter
} GridLocation_t;

#define NofValidGridLocation 9
extern char const * GridLocationName[NofValidGridLocation];

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      BCData Types: Can not add types and stay forward compatible      *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef enum {
	BCDataTypeNull, BCDataTypeUserDefined,
	Dirichlet, Neumann
} BCDataType_t;
#define NofValidBCDataTypes 4
extern char const * BCDataTypeName[NofValidBCDataTypes];

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *	Grid Connectivity Types 					 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef enum {
	GridConnectivityTypeNull, GridConnectivityTypeUserDefined,
	Overset, Abutting, Abutting1to1
} GridConnectivityType_t;

#define NofValidGridConnectivityTypes 5
extern char const * GridConnectivityTypeName[NofValidGridConnectivityTypes];

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *	Point Set Types: Can't add types and stay forward compatible
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef enum {
	PointSetTypeNull, PointSetTypeUserDefined,
        PointList,  PointListDonor,
        PointRange, PointRangeDonor,
	ElementRange, ElementList, CellListDonor
} PointSetType_t;

#define NofValidPointSetTypes 9
extern char const * PointSetTypeName[NofValidPointSetTypes];

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Governing Equations and Physical Models Types                    *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef enum {
	GoverningEquationsNull, GoverningEquationsUserDefined,
	FullPotential, Euler, NSLaminar, NSTurbulent,
	NSLaminarIncompressible, NSTurbulentIncompressible
} GoverningEquationsType_t;

/* Any model type will accept both ModelTypeNull and ModelTypeUserDefined.
** The following models will accept these values as vaild...
**
** GasModel_t: Ideal, VanderWaals, CaloricallyPerfect, ThermallyPerfect,
**    ConstantDensity, RedlichKwong
**
** ViscosityModel_t: Constant, PowerLaw, SutherlandLaw
**
** ThermalConductivityModel_t: PowerLaw, SutherlandLaw, ConstantPrandtl
**
** TurbulenceModel_t: Algebraic_BaldwinLomax, Algebraic_CebeciSmith,
**    HalfEquation_JohnsonKing, OneEquation_BaldwinBarth,
**    OneEquation_SpalartAllmaras, TwoEquation_JonesLaunder,
**    TwoEquation_MenterSST,TwoEquation_Wilcox
**
** TurbulenceClosure_t: EddyViscosity, ReynoldsStress, ReynoldsStressAlgebraic
**
** ThermalRelaxationModel_t: Frozen, ThermalEquilib, ThermalNonequilib
**
** ChemicalKineticsModel_t: Frozen, ChemicalEquilibCurveFit,
**    ChemicalEquilibMinimization, ChemicalNonequilib
**
** EMElectricFieldModel_t: Voltage, Interpolated, Constant, Frozen
**
** EMMagneticFieldModel_t: Interpolated, Constant, Frozen
**
** EMConductivityModel_t: Constant, Frozen, Equilibrium_LinRessler,
**				Chemistry_LinRessler
*/

typedef enum {
	ModelTypeNull, ModelTypeUserDefined,
	Ideal, VanderWaals,
	Constant,
	PowerLaw, SutherlandLaw,
	ConstantPrandtl,
	EddyViscosity, ReynoldsStress, ReynoldsStressAlgebraic,
	Algebraic_BaldwinLomax, Algebraic_CebeciSmith,
	HalfEquation_JohnsonKing, OneEquation_BaldwinBarth,
	OneEquation_SpalartAllmaras, TwoEquation_JonesLaunder,
	TwoEquation_MenterSST, TwoEquation_Wilcox,
	CaloricallyPerfect, ThermallyPerfect,
	ConstantDensity, RedlichKwong,
	Frozen, ThermalEquilib, ThermalNonequilib,
	ChemicalEquilibCurveFit, ChemicalEquilibMinimization,
	ChemicalNonequilib,
/* begin KMW */
	EMElectricField, EMMagneticField, EMConductivity,
	Voltage, Interpolated, Equilibrium_LinRessler, Chemistry_LinRessler
/* end KMW */
} ModelType_t;

#define NofValidGoverningEquationsTypes 8
/* begin KMW */
#define NofValidModelTypes 36
/* end KMW */

extern char const * GoverningEquationsTypeName[NofValidGoverningEquationsTypes];
extern char const * ModelTypeName[NofValidModelTypes];

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 * 	Boundary Condition Types					 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef enum {
	BCTypeNull, BCTypeUserDefined,
	BCAxisymmetricWedge, BCDegenerateLine, BCDegeneratePoint,
	BCDirichlet, BCExtrapolate, BCFarfield, BCGeneral, BCInflow,
	BCInflowSubsonic,  BCInflowSupersonic, BCNeumann, BCOutflow,
	BCOutflowSubsonic, BCOutflowSupersonic, BCSymmetryPlane,
	BCSymmetryPolar, BCTunnelInflow, BCTunnelOutflow, BCWall,
	BCWallInviscid, BCWallViscous, BCWallViscousHeatFlux,
	BCWallViscousIsothermal, FamilySpecified
} BCType_t;

#define NofValidBCTypes 26
extern char const * BCTypeName[NofValidBCTypes];

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Data types:  Can not add data types and stay forward compatible  *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef enum {
	DataTypeNull, DataTypeUserDefined, Integer, RealSingle,
	RealDouble, Character
} DataType_t;
#define NofValidDataTypes 6
extern char const * DataTypeName[NofValidDataTypes];

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Element types                                                    *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef enum {
	ElementTypeNull, ElementTypeUserDefined,	/* 0, 1,	*/
	NODE, BAR_2, BAR_3, 				/* 2, 3, 4, 	*/
	TRI_3, TRI_6,					/* 5, 6,	*/
	QUAD_4, QUAD_8, QUAD_9,				/* 7, 8, 9,	*/
	TETRA_4, TETRA_10, 				/* 10, 11,	*/
	PYRA_5, PYRA_14, 				/* 12, 13,	*/
	PENTA_6, PENTA_15, PENTA_18,			/* 14, 15, 16,	*/
	HEXA_8, HEXA_20, HEXA_27, 			/* 17, 18, 19,	*/
	MIXED, NGON_n					/* 20, 21+	*/
} ElementType_t;
#define NofValidElementTypes 22
extern char const * ElementTypeName[NofValidElementTypes];

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Zone types                                                       *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef enum {
	ZoneTypeNull, ZoneTypeUserDefined,
	Structured, Unstructured
} ZoneType_t;
#define NofValidZoneTypes 4
extern char const * ZoneTypeName[NofValidZoneTypes];

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Rigid Grid Motion types						 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef enum {
	RigidGridMotionTypeNull, RigidGridMotionTypeUserDefined,
	ConstantRate, VariableRate
} RigidGridMotionType_t;
#define NofValidRigidGridMotionTypes 4
extern char const * RigidGridMotionTypeName[NofValidRigidGridMotionTypes];

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Arbitrary Grid Motion types                                      *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef enum {
        ArbitraryGridMotionTypeNull, ArbitraryGridMotionTypeUserDefined,
        NonDeformingGrid, DeformingGrid
} ArbitraryGridMotionType_t;
#define NofValidArbitraryGridMotionTypes 4
extern char const * ArbitraryGridMotionTypeName[NofValidArbitraryGridMotionTypes];

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Simulation types					         *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef enum {
	SimulationTypeNull, SimulationTypeUserDefined,
	TimeAccurate, NonTimeAccurate
} SimulationType_t;
#define NofValidSimulationTypes 4
extern char const * SimulationTypeName[NofValidSimulationTypes];

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *	BC Property types						 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef enum {
	WallFunctionTypeNull, WallFunctionTypeUserDefined,
	Generic
} WallFunctionType_t;
#define NofValidWallFunctionTypes 3
extern char const * WallFunctionTypeName[NofValidWallFunctionTypes];

typedef enum {
	AreaTypeNull, AreaTypeUserDefined,
	BleedArea, CaptureArea
} AreaType_t;
#define NofValidAreaTypes 4
extern char const * AreaTypeName[NofValidAreaTypes];

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Grid Connectivity Property types				 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef enum {
	AverageInterfaceTypeNull, AverageInterfaceTypeUserDefined,
	AverageAll, AverageCircumferential, AverageRadial, AverageI,
	AverageJ, AverageK
} AverageInterfaceType_t;
#define NofValidAverageInterfaceTypes 8
extern char const * AverageInterfaceTypeName[NofValidAverageInterfaceTypes];

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      LIBRARY FUNCTIONS						 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_open(char const * filename, int mode, int *fn);
int CGNS_API cg_version(int fn, float *FileVersion);
int CGNS_API cg_close(int fn);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write CGNSBase_t Nodes					 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_nbases(int fn, int *nbases);
int CGNS_API cg_base_read(int file_number, int B, char *basename, int *cell_dim,
        int *phys_dim);
int CGNS_API cg_base_id(int fn, int B, double *base_id);
int CGNS_API cg_base_write(int file_number, char const * basename, int cell_dim,
	int phys_dim, int *B);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write Zone_t Nodes    					 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_nzones(int fn, int B, int *nzones);
int CGNS_API cg_zone_read(int fn, int B, int Z, char *zonename, int *size);
int CGNS_API cg_zone_type(int file_number, int B, int Z, ZoneType_t *type);
int CGNS_API cg_zone_id(int fn, int B, int Z, double *zone_id);
int CGNS_API cg_zone_write(int fn, int B, char const * zonename, int const * size,
	ZoneType_t type, int *Z);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write Family_t Nodes                                    *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_nfamilies(int file_number, int B, int *nfamilies);
int CGNS_API cg_family_read(int file_number, int B, int F, char *family_name,
         int *nboco, int *ngeos);
int CGNS_API cg_family_write(int file_number, int B, char const * family_name, int *F);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write FamilyName_t Nodes                                *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_famname_read(char *family_name);
int CGNS_API cg_famname_write(char const * family_name);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write FamilyBC_t Nodes                                  *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_fambc_read(int file_number, int B, int F, int BC, char *fambc_name,
	BCType_t *bocotype);
int CGNS_API cg_fambc_write(int file_number, int B, int F, char const * fambc_name,
        BCType_t bocotype, int *BC);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write GeometryReference_t Nodes                         *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_geo_read(int file_number, int B, int F, int G, char *geo_name,
        char **geo_file, char *CAD_name, int *npart);
int CGNS_API cg_geo_write(int file_number, int B, int F, char const * geo_name,
        char const * filename, char const * CADname, int *G);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write GeometryEntity_t Nodes                            *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_part_read(int file_number, int B, int F, int G, int P,
	char *part_name);
int CGNS_API cg_part_write(int file_number, int B, int F, int G, char const * part_name,
        int *P);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write GridCoordinates_t Nodes                           *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_ngrids(int file_number, int B, int Z, int *ngrids);
int CGNS_API cg_grid_read(int file_number, int B, int Z, int G, char *gridname);
int CGNS_API cg_grid_write(int file_number, int B, int Z, char const * zcoorname, int *G);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write GridCoordinates_t/DataArray_t Nodes               *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_ncoords(int fn, int B, int Z, int *ncoords);
int CGNS_API cg_coord_info(int fn, int B, int Z, int C, DataType_t *type, char *coordname);
int CGNS_API cg_coord_read(int fn, int B, int Z, char const * coordname, DataType_t type,
                  int const * rmin, int const * rmax, void *coord);
int CGNS_API cg_coord_id(int fn, int B, int Z, int C, double *coord_id);
int CGNS_API cg_coord_write(int fn, int B, int Z, DataType_t type, char const * coordname,
                   void const * coord_ptr, int *C);

/* begin KMW */
int CGNS_API cg_coord_partial_write(int fn, int B, int Z, DataType_t type,
			   char const * coordname, int *rmin, int *rmax,
			   void const * coord_ptr, int *C);

/* end KMW */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write Elements_t Nodes                                  *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_nsections(int file_number, int B, int Z, int *nsections);
int CGNS_API cg_section_read(int file_number, int B, int Z, int S, char *SectionName,
        ElementType_t *type, int *start, int *end, int *nbndry, int *parent_flag);
int CGNS_API cg_elements_read(int file_number, int B, int Z, int S, int *elements,
        int *parent_data);
int CGNS_API cg_section_write(int file_number, int B, int Z, char const * SectionName,
	ElementType_t type, int start, int end, int nbndry, int const * elements, int *S);
int CGNS_API cg_parent_data_write(int file_number, int B, int Z, int S, int const * parent_data);
int CGNS_API cg_npe(ElementType_t type, int *npe);
int CGNS_API cg_ElementDataSize(int file_number, int B, int Z, int S, int *ElementDataSize);

/* begin KMW */
int CGNS_API cg_section_partial_write(int file_number, int B, int Z,
			     char const * SectionName,
			     ElementType_t type, int start, int end,
			     int nbndry, int const * elements, int *S);

int CGNS_API cg_parent_data_partial_write(int fn, int B, int Z, int S,
				 int rmin, int rmax,
                                 int const *ParentData);

int CGNS_API cg_section_read_ext(int file_number, int B, int Z, int S,
                        char *SectionName, ElementType_t *type, int *start,
                        int *end, int *nbndry, int *parent_flag,
                        int *rmin_parent, int *rmax_parent);

int CGNS_API cg_elements_read_ext(int file_number, int B, int Z, int S,
			 int *elements, int rmin_elems, int rmax_elems,
			 int *parent_data, int rmin_parent, int rmax_parent);
/* end KMW */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write FlowSolution_t Nodes                              *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */


int CGNS_API cg_nsols(int fn, int B, int Z, int *nsols);
int CGNS_API cg_sol_info(int fn, int B, int Z, int S, char *solname, GridLocation_t *location);
int CGNS_API cg_sol_id(int fn, int B, int Z,int S, double *sol_id);
int CGNS_API cg_sol_write(int fn, int B, int Z, char const * solname, GridLocation_t location, int *S);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write solution DataArray_t Nodes                        *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_nfields(int fn, int B, int Z, int S, int *nfields);
int CGNS_API cg_field_info(int fn,int B,int Z,int S,int F, DataType_t *type, char *fieldname);
int CGNS_API cg_field_read(int fn, int B, int Z, int S, char *fieldname, DataType_t type,
		  int *rmin, int *rmax, void *field_ptr);
int CGNS_API cg_field_id(int fn, int B, int Z,int S,int F, double *field_id);
int CGNS_API cg_field_write(int fn,int B,int Z,int S, DataType_t type, char const * fieldname,
		   void const * field_ptr, int *F);

/* begin KMW */
int CGNS_API cg_field_partial_write(int fn, int B, int Z, int S, DataType_t type,
			   char const * fieldname, int *rmin, int *rmax,
			   void const * field_ptr, int *F);
/* end KMW */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write OversetHoles_t Nodes  				 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_nholes(int fn, int B, int Z, int *nholes);
int CGNS_API cg_hole_info(int fn, int B, int Z, int I, char *holename, GridLocation_t *location,
	         PointSetType_t *ptset_type, int *nptsets, int *npnts);
int CGNS_API cg_hole_read(int fn, int B, int Z, int I, int *pnts);
int CGNS_API cg_hole_id(int fn, int B, int Z, int I, double *hole_id);
int CGNS_API cg_hole_write(int fn, int B, int Z, char const * holename, GridLocation_t location,
		  PointSetType_t ptset_type, int nptsets, int npnts, int const * pnts, int *I);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write GridConnectivity_t Nodes                          *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_nconns(int fn, int B, int Z, int *nconns);
int CGNS_API cg_conn_info(int file_number, int B, int Z, int I, char *connectname,
                 GridLocation_t *location, GridConnectivityType_t *type,
                 PointSetType_t *ptset_type, int *npnts, char *donorname,
                 ZoneType_t *donor_zonetype, PointSetType_t *donor_ptset_type,
		 DataType_t *donor_datatype, int *ndata_donor);
int CGNS_API cg_conn_read(int file_number, int B, int Z, int I, int *pnts,
                 DataType_t donor_datatype, void *donor_data);
int CGNS_API cg_conn_id(int fn, int B, int Z, int I, double *conn_id);
int CGNS_API cg_conn_write(int file_number, int B, int Z,  char const * connectname, GridLocation_t location,
                  GridConnectivityType_t type, PointSetType_t ptset_type, int npnts, int const * pnts,
                  char const * donorname, ZoneType_t donor_zonetype,  PointSetType_t donor_ptset_type,
                  DataType_t donor_datatype, int ndata_donor, void const *donor_data, int *I);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write GridConnectivity1to1_t Nodes in a zone            *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_n1to1(int fn, int B, int Z, int *n1to1);
int CGNS_API cg_1to1_read(int fn, int B, int Z, int I, char *connectname, char *donorname,
		 int *range, int *donor_range, int *transform);
int CGNS_API cg_1to1_id(int fn, int B, int Z, int I, double *one21_id);
int CGNS_API cg_1to1_write(int fn, int B, int Z, char const * connectname, char const * donorname,
          int const * range, int const * donor_range, int const * transform, int *I);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read all GridConnectivity1to1_t Nodes of a base                  *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
int CGNS_API cg_n1to1_global(int fn, int B, int *n1to1_global);
int CGNS_API cg_1to1_read_global(int fn, int B, char **connectname, char **zonename,
			char **donorname, int **range, int **donor_range, int **transform);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write BC_t Nodes                                        *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_nbocos(int fn, int B, int Z, int *nbocos);
int CGNS_API cg_boco_info(int fn, int B, int Z, int BC, char *boconame,
	BCType_t *bocotype, PointSetType_t *ptset_type, int *npnts,
	int *NormalIndex, int *NormalListFlag, DataType_t *NormalDataType,
	int *ndataset);
int CGNS_API cg_boco_read(int fn, int B, int Z, int BC, int *pnts, void *NormalList);
int CGNS_API cg_boco_id(int fn, int B, int Z, int BC, double *boco_id);
int CGNS_API cg_boco_write(int file_number, int B, int Z, char const * boconame, BCType_t bocotype,
                  PointSetType_t ptset_type, int npnts, int const * pnts, int *BC);
int CGNS_API cg_boco_normal_write(int file_number, int B, int Z, int BC, int const * NormalIndex,
                 int NormalListFlag,  DataType_t NormalDataType, void const * NormalList);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write BCDataSet_t Nodes                                 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_dataset_read(int fn, int B, int Z, int BC, int DS, char *name,
	BCType_t *BCType, int *DirichletFlag, int *NeumannFlag);
int CGNS_API cg_dataset_write(int file_number, int B, int Z, int BC, char const * name,
        BCType_t BCType, int *Dset);

/* begin KMW */
int CGNS_API cg_bcdataset_write(char *name, BCType_t BCType, BCDataType_t BCDataType);
int CGNS_API cg_bcdataset_info(int *n_dataset);
int CGNS_API cg_bcdataset_read(int index, char *name, BCType_t *BCType,
		      int *DirichletFlag, int *NeumannFlag);
/* end KMW */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write BCData_t Nodes                                    *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_bcdata_write(int file_number, int B, int Z, int BC, int Dset,
        BCDataType_t BCDataType);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write DiscreteData_t Nodes                              *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_ndiscrete(int file_number, int B, int Z, int *ndiscrete);
int CGNS_API cg_discrete_read(int file_number, int B, int Z, int D, char *discrete_name);
int CGNS_API cg_discrete_write(int file_number, int B, int Z,  char const * discrete_name, int *D);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write RigidGridMotion_t Nodes				 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_n_rigid_motions(int file_number, int B, int Z, int *n_rigid_motions);
int CGNS_API cg_rigid_motion_read(int file_number, int B, int Z, int R, char *name,
        RigidGridMotionType_t *type);
int CGNS_API cg_rigid_motion_write(int file_number, int B, int Z, char const * name,
	RigidGridMotionType_t type, int *R);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write ArbitraryGridMotion_t Nodes                       *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_n_arbitrary_motions(int file_number, int B, int Z, int *n_arbitrary_motions);
int CGNS_API cg_arbitrary_motion_read(int file_number, int B, int Z, int A, char *name,
        ArbitraryGridMotionType_t *type);
int CGNS_API cg_arbitrary_motion_write(int file_number, int B, int Z, char const * amotionname,
        ArbitraryGridMotionType_t type, int *A);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write SimulationType_t Node                             *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_simulation_type_read(int file_number, int B, SimulationType_t *type);
int CGNS_API cg_simulation_type_write(int file_number, int B, SimulationType_t type);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write BaseIterativeData_t Node                          *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_biter_read(int file_number, int B, char *bitername, int *nsteps);
int CGNS_API cg_biter_write(int file_number, int B, char const * bitername, int nsteps);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write ZoneIterativeData_t Node                          *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_ziter_read(int file_number, int B, int Z, char *zitername);
int CGNS_API cg_ziter_write(int file_number, int B, int Z, char const * zitername);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write Gravity_t Nodes                                   *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_gravity_read(int file_number, int B, float *gravity_vector);
int CGNS_API cg_gravity_write(int file_number, int B, float const *gravity_vector);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write Axisymmetry_t Nodes                               *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_axisym_read(int file_number, int B, float *ref_point, float *axis);
int CGNS_API cg_axisym_write(int file_number, int B, float const *ref_point,
  	float const *axis);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write RotatingCoordinates_t Nodes                       *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_rotating_read(float *rot_rate, float *rot_center);
int CGNS_API cg_rotating_write(float const *rot_rate, float const *rot_center);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write BCProperty_t/WallFunction_t Nodes   	         *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_bc_wallfunction_read(int file_number, int B, int Z, int BC,
    WallFunctionType_t *WallFunctionType);
int CGNS_API cg_bc_wallfunction_write(int file_number, int B, int Z, int BC,
    WallFunctionType_t WallFunctionType);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write BCProperty_t/Area_t Nodes                         *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_bc_area_read(int file_number, int B, int Z, int BC,
    AreaType_t *AreaType, float *SurfaceArea, char *RegionName);
int CGNS_API cg_bc_area_write(int file_number, int B, int Z, int BC,
    AreaType_t AreaType, float SurfaceArea, char const *RegionName);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write GridConnectivityProperty_t/Periodic_t Nodes       *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_conn_periodic_read(int file_number, int B, int Z, int I,
    float *RotationCenter, float *RotationAngle, float *Translation);
int CGNS_API cg_conn_periodic_write(int file_number, int B, int Z, int I,
    float const *RotationCenter, float const *RotationAngle,
    float const *Translation);

/* begin KMW */
int CGNS_API cg_1to1_periodic_write(int file_number, int B, int Z, int I,
    float const *RotationCenter, float const *RotationAngle,
    float const *Translation);
int CGNS_API cg_1to1_periodic_read(int file_number, int B, int Z, int I,
    float *RotationCenter, float *RotationAngle, float *Translation);
/* end KMW */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *   Read and write GridConnectivityProperty_t/AverageInterface_t Nodes  *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_conn_average_read(int file_number, int B, int Z, int I,
    AverageInterfaceType_t *AverageInterfaceType);
int CGNS_API cg_conn_average_write(int file_number, int B, int Z, int I,
    AverageInterfaceType_t AverageInterfaceType);

/* begin KMW */
int CGNS_API cg_1to1_average_write(int file_number, int B, int Z, int I,
    AverageInterfaceType_t AverageInterfaceType);
int CGNS_API cg_1to1_average_read(int file_number, int B, int Z, int I,
    AverageInterfaceType_t *AverageInterfaceType);
/* end KMW */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Variable Argument List Functions                                 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_goto(int file_number, int B, ...);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write ConvergenceHistory_t Nodes                        *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_convergence_read(int *iterations, char **NormDefinitions);
int CGNS_API cg_convergence_write(int iterations, char const * NormDefinitions);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write ReferenceState_t Nodes                            *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_state_read(char **StateDescription);
int CGNS_API cg_state_write(char const * StateDescription);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write FlowEquationSet_t Nodes                           *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_equationset_read(int *EquationDimension,
        int *GoverningEquationsFlag, int *GasModelFlag,
        int *ViscosityModelFlag,     int *ThermalConductivityModelFlag,
        int *TurbulenceClosureFlag,  int *TurbulenceModelFlag);
int CGNS_API cg_equationset_chemistry_read(int *ThermalRelaxationFlag,
	int *ChemicalKineticsFlag);
/* begin KMW */
int CGNS_API cg_equationset_elecmagn_read(int *ElecFldModelFlag,
				 int *MagnFldModelFlag,
				 int *ConductivityModelFlag);
/* end KMW */
int CGNS_API cg_equationset_write(int EquationDimension);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write GoverningEquations_t Nodes                        *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_governing_read(GoverningEquationsType_t *EquationsType);
int CGNS_API cg_governing_write(GoverningEquationsType_t Equationstype);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write Diffusion Model Nodes                             *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_diffusion_read(int *diffusion_model);
int CGNS_API cg_diffusion_write(int const * diffusion_model);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write GasModel_t, ViscosityModel_t,                     *
 *      ThermalConductivityModel_t, TurbulenceClosure_t,                 *
 *      TurbulenceModel_t, ThermalRelaxationModel_t,                     *
 *      ChemicalKineticsModel_t, EMElectricFieldModel_t,                 *
 *      EMMagneticFieldModel_t Nodes                                     *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_model_read(char *ModelLabel, ModelType_t *ModelType);
int CGNS_API cg_model_write(char const * ModelLabel, ModelType_t ModelType);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write DataArray_t Nodes                                 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_narrays(int *narrays);
int CGNS_API cg_array_info(int A, char *ArrayName, DataType_t *DataType,
        int *DataDimension, int *DimensionVector);
int CGNS_API cg_array_read(int A, void *Data);
int CGNS_API cg_array_read_as(int A, DataType_t type, void *Data);
int CGNS_API cg_array_write(char const * ArrayName, DataType_t DataType,
        int DataDimension, int const * DimensionVector, void const * Data);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write UserDefinedData_t Nodes - new in version 2.1      *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_nuser_data(int *nuser_data);
int CGNS_API cg_user_data_read(int Index, char *user_data_name);
int CGNS_API cg_user_data_write(char const * user_data_name);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write IntegralData_t Nodes                              *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_nintegrals(int *nintegrals);
int CGNS_API cg_integral_read(int IntegralDataIndex, char *IntegralDataName);
int CGNS_API cg_integral_write(char const * IntegralDataName);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write Rind_t Nodes                                      *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_rind_read(int *RindData);
int CGNS_API cg_rind_write(int const * RindData);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write Descriptor_t Nodes                                *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_ndescriptors(int *ndescriptors);
int CGNS_API cg_descriptor_read(int descr_no, char *descr_name, char **descr_text);
int CGNS_API cg_descriptor_write(char const * descr_name, char const * descr_text);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write DimensionalUnits_t Nodes                          *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_nunits(int *nunits);
int CGNS_API cg_units_read(MassUnits_t *mass, LengthUnits_t *length, TimeUnits_t *time,
        TemperatureUnits_t *temperature, AngleUnits_t *angle);
int CGNS_API cg_units_write(MassUnits_t mass, LengthUnits_t length, TimeUnits_t time,
        TemperatureUnits_t temperature, AngleUnits_t angle);
int CGNS_API cg_unitsfull_read(MassUnits_t *mass, LengthUnits_t *length,
    TimeUnits_t *time, TemperatureUnits_t *temperature, AngleUnits_t *angle,
    ElectricCurrentUnits_t *current, SubstanceAmountUnits_t *amount,
    LuminousIntensityUnits_t *intensity);
int CGNS_API cg_unitsfull_write(MassUnits_t mass, LengthUnits_t length,
    TimeUnits_t time, TemperatureUnits_t temperature, AngleUnits_t angle,
    ElectricCurrentUnits_t current, SubstanceAmountUnits_t amount,
    LuminousIntensityUnits_t intensity);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write DimensionalExponents_t Nodes                      *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_exponents_info(DataType_t *DataType);
int CGNS_API cg_nexponents(int *numexp);
int CGNS_API cg_exponents_read(void *exponents);
int CGNS_API cg_exponents_write(DataType_t DataType, void const * exponents);

/* begin KMW */
int CGNS_API cg_expfull_read(void *exponents);
int CGNS_API cg_expfull_write(DataType_t DataType, void const * exponents);
/* end KMW */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write DataConversion_t Nodes                            *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_conversion_info(DataType_t *DataType);
int CGNS_API cg_conversion_read(void *ConversionFactors);
int CGNS_API cg_conversion_write(DataType_t DataType, void const * ConversionFactors);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write DataClass_t Nodes                                 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_dataclass_read(DataClass_t *dataclass);
int CGNS_API cg_dataclass_write(DataClass_t dataclass);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write GridLocation_t Nodes                              *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_gridlocation_read(GridLocation_t *GridLocation);
int CGNS_API cg_gridlocation_write(GridLocation_t GridLocation);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write Ordinal_t Nodes                                   *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_ordinal_read(int *Ordinal);
int CGNS_API cg_ordinal_write(int Ordinal);

/* begin KMW */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write IndexArray/Range_t Nodes  - new in version 2.4    *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_ptset_info(PointSetType_t *ptset_type, int *npnts);
int CGNS_API cg_ptset_write(PointSetType_t ptset_type, int npnts, int const *pnts);
int CGNS_API cg_ptset_read(int *pnts);

/* end KMW */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Link Handling Functions - new in version 2.1                     *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_is_link(int *path_length);
int CGNS_API cg_link_read(char **filename, char **link_path);
int CGNS_API cg_link_write(char const * nodename, char const * filename, char const * name_in_file);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      General Delete Function						 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int CGNS_API cg_delete_node(char *node_name);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Error Handling Functions                                         *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNS_API char const * cg_get_error(void);
void CGNS_API cg_error_exit(void);
void CGNS_API cg_error_print(void);

#ifdef __cplusplus
}
#endif
#endif
