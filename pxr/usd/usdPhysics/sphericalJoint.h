//
// Copyright 2016 Pixar
//
// Licensed under the Apache License, Version 2.0 (the "Apache License")
// with the following modification; you may not use this file except in
// compliance with the Apache License and the following modification to it:
// Section 6. Trademarks. is deleted and replaced with:
//
// 6. Trademarks. This License does not grant permission to use the trade
//    names, trademarks, service marks, or product names of the Licensor
//    and its affiliates, except as required to comply with Section 4(c) of
//    the License and to reproduce the content of the NOTICE file.
//
// You may obtain a copy of the Apache License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the Apache License with the above modification is
// distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied. See the Apache License for the specific
// language governing permissions and limitations under the Apache License.
//
#ifndef USDPHYSICS_GENERATED_SPHERICALJOINT_H
#define USDPHYSICS_GENERATED_SPHERICALJOINT_H

/// \file usdPhysics/sphericalJoint.h

#include "pxr/pxr.h"
#include "pxr/usd/usdPhysics/api.h"
#include "pxr/usd/usdPhysics/joint.h"
#include "pxr/usd/usd/prim.h"
#include "pxr/usd/usd/stage.h"
#include "pxr/usd/usdPhysics/tokens.h"

#include "pxr/base/vt/value.h"

#include "pxr/base/gf/vec3d.h"
#include "pxr/base/gf/vec3f.h"
#include "pxr/base/gf/matrix4d.h"

#include "pxr/base/tf/token.h"
#include "pxr/base/tf/type.h"

PXR_NAMESPACE_OPEN_SCOPE

class SdfAssetPath;

// -------------------------------------------------------------------------- //
// PHYSICSSPHERICALJOINT                                                      //
// -------------------------------------------------------------------------- //

/// \class UsdPhysicsSphericalJoint
///
/// Predefined spherical joint type that removes linear degrees of 
/// freedom, and that provides three rotational degrees of freedom by default.
/// The rotations can be limited with the cone and axis limit attributes:
/// 
/// The lower and upper axis-limit attributes limit rotation around the joint
/// axis. The axis rotation is locked when the lower limit is larger than the
/// upper limit.
/// 
/// The cone angle 0 and 1 limits create a cone limit with the the joint axis
/// equal to the cone axis; the cone limit is circular if the two cone angles
/// are equal, and the cone limit is elliptical if the angles are not equal.
/// 
/// Given the joint-axis token, the two cone limit angles map to the specific
/// joint-frame rotation axes as follows:
/// 
/// Joint Axis   |   Cone Angle0 limits   |   Cone Angle 1 limits
/// -------------|------------------------|----------------------
/// X        |          Y             |          Z
/// Y        |          Z             |          X
/// Z        |          X             |          Y
/// 
/// Example: Shown are the aligned spherical-joint frames centered between two
/// rigid bodies to be joined. The joint axis is set to Y (green), the Cone
/// Angle 0 is set to 10 degrees and Cone Angle 1 is set to 45 degrees. Note the
/// narrower cone extent for the rotation around the Z axis (blue) compared to
/// the X axis (red) rotation.
/// 
/// \image html UsdPhysicsSphericalJointLimitCone.png
/// 
///
/// For any described attribute \em Fallback \em Value or \em Allowed \em Values below
/// that are text/tokens, the actual token is published and defined in \ref UsdPhysicsTokens.
/// So to set an attribute to the value "rightHanded", use UsdPhysicsTokens->rightHanded
/// as the value.
///
class UsdPhysicsSphericalJoint : public UsdPhysicsJoint
{
public:
    /// Compile time constant representing what kind of schema this class is.
    ///
    /// \sa UsdSchemaKind
    static const UsdSchemaKind schemaKind = UsdSchemaKind::ConcreteTyped;

    /// Construct a UsdPhysicsSphericalJoint on UsdPrim \p prim .
    /// Equivalent to UsdPhysicsSphericalJoint::Get(prim.GetStage(), prim.GetPath())
    /// for a \em valid \p prim, but will not immediately throw an error for
    /// an invalid \p prim
    explicit UsdPhysicsSphericalJoint(const UsdPrim& prim=UsdPrim())
        : UsdPhysicsJoint(prim)
    {
    }

    /// Construct a UsdPhysicsSphericalJoint on the prim held by \p schemaObj .
    /// Should be preferred over UsdPhysicsSphericalJoint(schemaObj.GetPrim()),
    /// as it preserves SchemaBase state.
    explicit UsdPhysicsSphericalJoint(const UsdSchemaBase& schemaObj)
        : UsdPhysicsJoint(schemaObj)
    {
    }

    /// Destructor.
    USDPHYSICS_API
    virtual ~UsdPhysicsSphericalJoint();

    /// Return a vector of names of all pre-declared attributes for this schema
    /// class and all its ancestor classes.  Does not include attributes that
    /// may be authored by custom/extended methods of the schemas involved.
    USDPHYSICS_API
    static const TfTokenVector &
    GetSchemaAttributeNames(bool includeInherited=true);

    /// Return a UsdPhysicsSphericalJoint holding the prim adhering to this
    /// schema at \p path on \p stage.  If no prim exists at \p path on
    /// \p stage, or if the prim at that path does not adhere to this schema,
    /// return an invalid schema object.  This is shorthand for the following:
    ///
    /// \code
    /// UsdPhysicsSphericalJoint(stage->GetPrimAtPath(path));
    /// \endcode
    ///
    USDPHYSICS_API
    static UsdPhysicsSphericalJoint
    Get(const UsdStagePtr &stage, const SdfPath &path);

    /// Attempt to ensure a \a UsdPrim adhering to this schema at \p path
    /// is defined (according to UsdPrim::IsDefined()) on this stage.
    ///
    /// If a prim adhering to this schema at \p path is already defined on this
    /// stage, return that prim.  Otherwise author an \a SdfPrimSpec with
    /// \a specifier == \a SdfSpecifierDef and this schema's prim type name for
    /// the prim at \p path at the current EditTarget.  Author \a SdfPrimSpec s
    /// with \p specifier == \a SdfSpecifierDef and empty typeName at the
    /// current EditTarget for any nonexistent, or existing but not \a Defined
    /// ancestors.
    ///
    /// The given \a path must be an absolute prim path that does not contain
    /// any variant selections.
    ///
    /// If it is impossible to author any of the necessary PrimSpecs, (for
    /// example, in case \a path cannot map to the current UsdEditTarget's
    /// namespace) issue an error and return an invalid \a UsdPrim.
    ///
    /// Note that this method may return a defined prim whose typeName does not
    /// specify this schema class, in case a stronger typeName opinion overrides
    /// the opinion at the current EditTarget.
    ///
    USDPHYSICS_API
    static UsdPhysicsSphericalJoint
    Define(const UsdStagePtr &stage, const SdfPath &path);

protected:
    /// Returns the kind of schema this class belongs to.
    ///
    /// \sa UsdSchemaKind
    USDPHYSICS_API
    UsdSchemaKind _GetSchemaKind() const override;

private:
    // needs to invoke _GetStaticTfType.
    friend class UsdSchemaRegistry;
    USDPHYSICS_API
    static const TfType &_GetStaticTfType();

    static bool _IsTypedSchema();

    // override SchemaBase virtuals.
    USDPHYSICS_API
    const TfType &_GetTfType() const override;

public:
    // --------------------------------------------------------------------- //
    // AXIS 
    // --------------------------------------------------------------------- //
    /// Joint axis.
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `uniform token physics:axis = "X"` |
    /// | C++ Type | TfToken |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Token |
    /// | \ref SdfVariability "Variability" | SdfVariabilityUniform |
    /// | \ref UsdPhysicsTokens "Allowed Values" | X, Y, Z |
    USDPHYSICS_API
    UsdAttribute GetAxisAttr() const;

    /// See GetAxisAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSICS_API
    UsdAttribute CreateAxisAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // CONEANGLE0LIMIT 
    // --------------------------------------------------------------------- //
    /// Cone angle that limits rotation symmetrically around the axis
    /// next to the joint axis. The next axis of X is Y, and of Z is X.
    /// A negative value means not limited. Units: degrees.
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `float physics:coneAngle0Limit = -1` |
    /// | C++ Type | float |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Float |
    USDPHYSICS_API
    UsdAttribute GetConeAngle0LimitAttr() const;

    /// See GetConeAngle0LimitAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSICS_API
    UsdAttribute CreateConeAngle0LimitAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // CONEANGLE1LIMIT 
    // --------------------------------------------------------------------- //
    /// Cone angle that limits rotation symmetrically around the axis
    /// second to next to the joint axis. The second to next axis of X is Z,
    /// and of Z is Y. A negative value means not limited. Units: degrees.
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `float physics:coneAngle1Limit = -1` |
    /// | C++ Type | float |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Float |
    USDPHYSICS_API
    UsdAttribute GetConeAngle1LimitAttr() const;

    /// See GetConeAngle1LimitAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSICS_API
    UsdAttribute CreateConeAngle1LimitAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // LOWERAXISLIMIT 
    // --------------------------------------------------------------------- //
    /// Lower limit on rotation around the joint axis. Default -inf
    /// means not limited in negative direction. The axis is locked if the lower
    /// limit is larger than the upper limit. Units: degrees
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `float physics:lowerAxisLimit = -inf` |
    /// | C++ Type | float |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Float |
    USDPHYSICS_API
    UsdAttribute GetLowerAxisLimitAttr() const;

    /// See GetLowerAxisLimitAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSICS_API
    UsdAttribute CreateLowerAxisLimitAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // UPPERAXISLIMIT 
    // --------------------------------------------------------------------- //
    /// Upper limit on rotation around the joint axis. Default inf
    /// means not limited in positive direction. The axis is locked if the lower
    /// limit is larger than the upper limit. Units: degrees
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `float physics:upperAxisLimit = inf` |
    /// | C++ Type | float |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Float |
    USDPHYSICS_API
    UsdAttribute GetUpperAxisLimitAttr() const;

    /// See GetUpperAxisLimitAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSICS_API
    UsdAttribute CreateUpperAxisLimitAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // ===================================================================== //
    // Feel free to add custom code below this line, it will be preserved by 
    // the code generator. 
    //
    // Just remember to: 
    //  - Close the class declaration with }; 
    //  - Close the namespace with PXR_NAMESPACE_CLOSE_SCOPE
    //  - Close the include guard with #endif
    // ===================================================================== //
    // --(BEGIN CUSTOM CODE)--
};

PXR_NAMESPACE_CLOSE_SCOPE

#endif
