/*
* All or portions of this file Copyright (c) Amazon.com, Inc. or its affiliates or
* its licensors.
*
* For complete copyright and license terms please see the LICENSE at the root of this
* distribution (the "License"). All use of this software is governed by the License,
* or, if provided, by the license below or the license accompanying this file. Do not
* remove or modify any license notices. This file is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*
*/

#pragma once

#include <AzCore/Component/ComponentBus.h>

namespace LmbrCentral
{
    /**
     * Type ID for SphereShapeComponent
     */
    static const AZ::Uuid SphereShapeComponentTypeId = "{E24CBFF0-2531-4F8D-A8AB-47AF4D54BCD2}";

    /**
     * Type ID for EditorSphereShapeComponent
     */
    static const AZ::Uuid EditorSphereShapeComponentTypeId = "{2EA56CBF-63C8-41D9-84D5-0EC2BECE748E}";

    /**
     * Configuration data for SphereShapeComponent
     */
    class SphereShapeConfig
        : public AZ::ComponentConfig
    {
    public:
        AZ_CLASS_ALLOCATOR(SphereShapeConfig, AZ::SystemAllocator, 0);
        AZ_RTTI(SphereShapeConfig, "{4AADFD75-48A7-4F31-8F30-FE4505F09E35}", ComponentConfig);
        
        static void Reflect(AZ::ReflectContext* context);

        SphereShapeConfig() = default;
        explicit SphereShapeConfig(float radius) : m_radius(radius) {}

        void SetRadius(float radius)
        {
            AZ_WarningOnce("LmbrCentral", false, "SetRadius Deprecated - Please use m_radius");
            m_radius = radius;
        }

        float GetRadius() const
        {
            AZ_WarningOnce("LmbrCentral", false, "GetRadius Deprecated - Please use m_radius");
            return m_radius;
        }

        float m_radius = 0.5f;
    };

    using SphereShapeConfiguration = SphereShapeConfig; ///< @deprecated Use SphereShapeConfig.

    /**
     * Services provided by the Sphere Shape Component.
     */
    class SphereShapeComponentRequests 
        : public AZ::ComponentBus
    {
    public:
        virtual SphereShapeConfig GetSphereConfiguration() = 0;

        /**
         * @brief Returns the radius for the sphere shape component.
         */
        virtual float GetRadius() = 0;

        /**
         * @brief Sets the radius for the sphere shape component.
         * @param radius new Radius of the sphere shape.
         */
        virtual void SetRadius(float radius) = 0;
    };

    // Bus to service the Sphere Shape component event group
    using SphereShapeComponentRequestsBus = AZ::EBus<SphereShapeComponentRequests>;

} // namespace LmbrCentral