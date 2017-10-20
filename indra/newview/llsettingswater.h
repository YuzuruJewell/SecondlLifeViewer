/**
* @file llsettingssky.h
* @author optional
* @brief A base class for asset based settings groups.
*
* $LicenseInfo:2011&license=viewerlgpl$
* Second Life Viewer Source Code
* Copyright (C) 2017, Linden Research, Inc.
*
* This library is free software; you can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public
* License as published by the Free Software Foundation;
* version 2.1 of the License only.
*
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public
* License along with this library; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*
* Linden Research, Inc., 945 Battery Street, San Francisco, CA  94111  USA
* $/LicenseInfo$
*/

#ifndef LL_SETTINGS_WATER_H
#define LL_SETTINGS_WATER_H

#include "llsettingsbase.h"

class LLSettingsWater : public LLSettingsBase
{
public:
    static const std::string SETTING_BLUR_MULTIPILER;
    static const std::string SETTING_FOG_COLOR;
    static const std::string SETTING_FOG_DENSITY;
    static const std::string SETTING_FOG_MOD;
    static const std::string SETTING_FRESNEL_OFFSET;
    static const std::string SETTING_FRESNEL_SCALE;
    static const std::string SETTING_NAME;
    static const std::string SETTING_NORMAL_MAP;
    static const std::string SETTING_NORMAL_SCALE;
    static const std::string SETTING_SCALE_ABOVE;
    static const std::string SETTING_SCALE_BELOW;
    static const std::string SETTING_WAVE1_DIR;
    static const std::string SETTING_WAVE2_DIR;

    static const LLUUID DEFAULT_WATER_NORMAL_ID;

    typedef boost::shared_ptr<LLSettingsWater> ptr_t;

    //---------------------------------------------------------------------
    LLSettingsWater(const LLSD &data);
    virtual ~LLSettingsWater() { };

    static ptr_t    buildFromLegacyPreset(const std::string &name, const LLSD &oldsettings);
    static ptr_t    buildDefaultWater();
    ptr_t           buildClone();

    //---------------------------------------------------------------------
    virtual std::string getSettingType() const { return std::string("water"); }

    // Settings status 
    virtual LLSettingsBase::ptr_t blend(const LLSettingsBase::ptr_t &end, F32 blendf) const;

    static LLSD defaults();

    //---------------------------------------------------------------------
    F32 getBlurMultiplier() const
    {   
        return mSettings[SETTING_BLUR_MULTIPILER].asReal();
    }

    void setBlurMultiplier(F32 val)
    {
        setValue(SETTING_BLUR_MULTIPILER, val);
    }

    LLColor3 getFogColor() const
    {
        return LLColor3(mSettings[SETTING_FOG_COLOR]);
    }

    void setFogColor(LLColor3 val)
    {
        setValue(SETTING_FOG_COLOR, val);
    }

    F32 getFogDensity() const
    {
        return mSettings[SETTING_FOG_DENSITY].asReal();
    }

    void setFogDensity(F32 val)
    {
        setValue(SETTING_FOG_DENSITY, val);
    }

    F32 getFogMod() const
    {
        return mSettings[SETTING_FOG_MOD].asReal();
    }

    void setFogMod(F32 val)
    {
        setValue(SETTING_FOG_MOD, val);
    }

    F32 getFresnelOffset() const
    {
        return mSettings[SETTING_FRESNEL_OFFSET].asReal();
    }

    void setFresnelOffset(F32 val)
    {
        setValue(SETTING_FRESNEL_OFFSET, val);
    }

    F32 getFresnelScale() const
    {
        return mSettings[SETTING_FRESNEL_SCALE].asReal();
    }

    void setFresnelScale(F32 val)
    {
        setValue(SETTING_FRESNEL_SCALE, val);
    }

    LLUUID getNormalMapID() const
    {
        return mSettings[SETTING_NORMAL_MAP].asUUID();
    }

    void setNormalMapID(LLUUID val)
    {
        setValue(SETTING_NORMAL_MAP, val);
    }

    LLVector3 getNormalScale() const
    {
        return LLVector3(mSettings[SETTING_NORMAL_SCALE]);
    }

    void setNormalScale(LLVector3 val)
    {
        setValue(SETTING_NORMAL_SCALE, val);
    }

    F32 getScaleAbove() const
    {
        return mSettings[SETTING_SCALE_ABOVE].asReal();
    }

    void setScaleAbove(F32 val)
    {
        setValue(SETTING_SCALE_ABOVE, val);
    }

    F32 getScaleBelow() const
    {
        return mSettings[SETTING_SCALE_BELOW].asReal();
    }

    void setScaleBelow(F32 val)
    {
        setValue(SETTING_SCALE_BELOW, val);
    }

    LLVector2 getWave1Dir() const
    {
        return LLVector2(mSettings[SETTING_WAVE1_DIR]);
    }

    void setWave1Dir(LLVector2 val)
    {
        setValue(SETTING_WAVE1_DIR, val);
    }

    LLVector2 getWave2Dir() const
    {
        return LLVector2(mSettings[SETTING_WAVE2_DIR]);
    }

    void setWave2Dir(LLVector2 val)
    {
        setValue(SETTING_WAVE2_DIR, val);
    }

    //-------------------------------------------
    LLVector4 getWaterPlane() const
    {
        update();
        return mWaterPlane;
    }

    F32 getWaterFogKS() const
    {
        update();
        return mWaterFogKS;
    }

protected:
    LLSettingsWater();

    virtual void        updateSettings();

    virtual parammapping_t getParameterMap() const;

    virtual void        applySpecial(void *);


private:
    static const std::string SETTING_LEGACY_BLUR_MULTIPILER;
    static const std::string SETTING_LEGACY_FOG_COLOR;
    static const std::string SETTING_LEGACY_FOG_DENSITY;
    static const std::string SETTING_LEGACY_FOG_MOD;
    static const std::string SETTING_LEGACY_FRESNEL_OFFSET;
    static const std::string SETTING_LEGACY_FRESNEL_SCALE;
    static const std::string SETTING_LEGACY_NORMAL_MAP;
    static const std::string SETTING_LEGACY_NORMAL_SCALE;
    static const std::string SETTING_LEGACY_SCALE_ABOVE;
    static const std::string SETTING_LEGACY_SCALE_BELOW;
    static const std::string SETTING_LEGACY_WAVE1_DIR;
    static const std::string SETTING_LEGACY_WAVE2_DIR;

    static const F32    WATER_FOG_LIGHT_CLAMP;

    LLVector4           mWaterPlane;
    F32                 mWaterFogKS;
};

#endif
