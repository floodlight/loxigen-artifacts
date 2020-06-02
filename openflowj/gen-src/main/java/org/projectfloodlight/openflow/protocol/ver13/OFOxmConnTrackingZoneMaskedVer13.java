// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_class.java
// Do not modify

package org.projectfloodlight.openflow.protocol.ver13;

import org.projectfloodlight.openflow.protocol.*;
import org.projectfloodlight.openflow.protocol.action.*;
import org.projectfloodlight.openflow.protocol.actionid.*;
import org.projectfloodlight.openflow.protocol.bsntlv.*;
import org.projectfloodlight.openflow.protocol.errormsg.*;
import org.projectfloodlight.openflow.protocol.meterband.*;
import org.projectfloodlight.openflow.protocol.instruction.*;
import org.projectfloodlight.openflow.protocol.instructionid.*;
import org.projectfloodlight.openflow.protocol.match.*;
import org.projectfloodlight.openflow.protocol.stat.*;
import org.projectfloodlight.openflow.protocol.oxm.*;
import org.projectfloodlight.openflow.protocol.oxs.*;
import org.projectfloodlight.openflow.protocol.queueprop.*;
import org.projectfloodlight.openflow.types.*;
import org.projectfloodlight.openflow.util.*;
import org.projectfloodlight.openflow.exceptions.*;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import java.util.Set;
import io.netty.buffer.ByteBuf;
import com.google.common.hash.PrimitiveSink;
import com.google.common.hash.Funnel;

class OFOxmConnTrackingZoneMaskedVer13 implements OFOxmConnTrackingZoneMasked {
    private static final Logger logger = LoggerFactory.getLogger(OFOxmConnTrackingZoneMaskedVer13.class);
    // version: 1.3
    final static byte WIRE_VERSION = 4;
    final static int LENGTH = 8;

        private final static U16 DEFAULT_VALUE = U16.ZERO;
        private final static U16 DEFAULT_VALUE_MASK = U16.ZERO;

    // OF message fields
    private final U16 value;
    private final U16 mask;
//
    // Immutable default instance
    final static OFOxmConnTrackingZoneMaskedVer13 DEFAULT = new OFOxmConnTrackingZoneMaskedVer13(
        DEFAULT_VALUE, DEFAULT_VALUE_MASK
    );

    // package private constructor - used by readers, builders, and factory
    OFOxmConnTrackingZoneMaskedVer13(U16 value, U16 mask) {
        if(value == null) {
            throw new NullPointerException("OFOxmConnTrackingZoneMaskedVer13: property value cannot be null");
        }
        if(mask == null) {
            throw new NullPointerException("OFOxmConnTrackingZoneMaskedVer13: property mask cannot be null");
        }
        this.value = value;
        this.mask = mask;
    }

    // Accessors for OF message fields
    @Override
    public U16 getMask() {
        return mask;
    }

    @Override
    public long getTypeLen() {
        return 0x1d504L;
    }

    @Override
    public U16 getValue() {
        return value;
    }

    public OFOxm<U16> getCanonical() {
        if (U16.NO_MASK.equals(mask)) {
            return new OFOxmConnTrackingZoneVer13(value);
        } else if(U16.FULL_MASK.equals(mask)) {
            return null;
        } else {
            return this;
        }
    }

    @Override
    public boolean isMasked() {
        return true;
    }

    @Override
    public MatchField<U16> getMatchField() {
        return MatchField.CONN_TRACKING_ZONE;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_13;
    }



    public OFOxmConnTrackingZoneMasked.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFOxmConnTrackingZoneMasked.Builder {
        final OFOxmConnTrackingZoneMaskedVer13 parentMessage;

        // OF message fields
        private boolean valueSet;
        private U16 value;
        private boolean maskSet;
        private U16 mask;

        BuilderWithParent(OFOxmConnTrackingZoneMaskedVer13 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public U16 getMask() {
        return mask;
    }

    @Override
    public OFOxmConnTrackingZoneMasked.Builder setMask(U16 mask) {
        this.mask = mask;
        this.maskSet = true;
        return this;
    }
    @Override
    public long getTypeLen() {
        return 0x1d504L;
    }

    @Override
    public U16 getValue() {
        return value;
    }

    @Override
    public OFOxmConnTrackingZoneMasked.Builder setValue(U16 value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public OFOxm<U16> getCanonical()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property canonical not supported in version 1.3");
    }

    @Override
    public boolean isMasked() {
        return true;
    }

    @Override
    public MatchField<U16> getMatchField() {
        return MatchField.CONN_TRACKING_ZONE;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_13;
    }



        @Override
        public OFOxmConnTrackingZoneMasked build() {
                U16 value = this.valueSet ? this.value : parentMessage.value;
                if(value == null)
                    throw new NullPointerException("Property value must not be null");
                U16 mask = this.maskSet ? this.mask : parentMessage.mask;
                if(mask == null)
                    throw new NullPointerException("Property mask must not be null");

                //
                return new OFOxmConnTrackingZoneMaskedVer13(
                    value,
                    mask
                );
        }

    }

    static class Builder implements OFOxmConnTrackingZoneMasked.Builder {
        // OF message fields
        private boolean valueSet;
        private U16 value;
        private boolean maskSet;
        private U16 mask;

    @Override
    public U16 getMask() {
        return mask;
    }

    @Override
    public OFOxmConnTrackingZoneMasked.Builder setMask(U16 mask) {
        this.mask = mask;
        this.maskSet = true;
        return this;
    }
    @Override
    public long getTypeLen() {
        return 0x1d504L;
    }

    @Override
    public U16 getValue() {
        return value;
    }

    @Override
    public OFOxmConnTrackingZoneMasked.Builder setValue(U16 value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public OFOxm<U16> getCanonical()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property canonical not supported in version 1.3");
    }

    @Override
    public boolean isMasked() {
        return true;
    }

    @Override
    public MatchField<U16> getMatchField() {
        return MatchField.CONN_TRACKING_ZONE;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_13;
    }

//
        @Override
        public OFOxmConnTrackingZoneMasked build() {
            U16 value = this.valueSet ? this.value : DEFAULT_VALUE;
            if(value == null)
                throw new NullPointerException("Property value must not be null");
            U16 mask = this.maskSet ? this.mask : DEFAULT_VALUE_MASK;
            if(mask == null)
                throw new NullPointerException("Property mask must not be null");


            return new OFOxmConnTrackingZoneMaskedVer13(
                    value,
                    mask
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFOxmConnTrackingZoneMasked> {
        @Override
        public OFOxmConnTrackingZoneMasked readFrom(ByteBuf bb) throws OFParseError {
            // fixed value property typeLen == 0x1d504L
            int typeLen = bb.readInt();
            if(typeLen != 0x1d504)
                throw new OFParseError("Wrong typeLen: Expected=0x1d504L(0x1d504L), got="+typeLen);
            U16 value = U16.of(bb.readShort());
            U16 mask = U16.of(bb.readShort());

            OFOxmConnTrackingZoneMaskedVer13 oxmConnTrackingZoneMaskedVer13 = new OFOxmConnTrackingZoneMaskedVer13(
                    value,
                      mask
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", oxmConnTrackingZoneMaskedVer13);
            return oxmConnTrackingZoneMaskedVer13;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFOxmConnTrackingZoneMaskedVer13Funnel FUNNEL = new OFOxmConnTrackingZoneMaskedVer13Funnel();
    static class OFOxmConnTrackingZoneMaskedVer13Funnel implements Funnel<OFOxmConnTrackingZoneMaskedVer13> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFOxmConnTrackingZoneMaskedVer13 message, PrimitiveSink sink) {
            // fixed value property typeLen = 0x1d504L
            sink.putInt(0x1d504);
            message.value.putTo(sink);
            message.mask.putTo(sink);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFOxmConnTrackingZoneMaskedVer13> {
        @Override
        public void write(ByteBuf bb, OFOxmConnTrackingZoneMaskedVer13 message) {
            // fixed value property typeLen = 0x1d504L
            bb.writeInt(0x1d504);
            bb.writeShort(message.value.getRaw());
            bb.writeShort(message.mask.getRaw());


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFOxmConnTrackingZoneMaskedVer13(");
        b.append("value=").append(value);
        b.append(", ");
        b.append("mask=").append(mask);
        b.append(")");
        return b.toString();
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        OFOxmConnTrackingZoneMaskedVer13 other = (OFOxmConnTrackingZoneMaskedVer13) obj;

        if (value == null) {
            if (other.value != null)
                return false;
        } else if (!value.equals(other.value))
            return false;
        if (mask == null) {
            if (other.mask != null)
                return false;
        } else if (!mask.equals(other.mask))
            return false;
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;

        result = prime * result + ((value == null) ? 0 : value.hashCode());
        result = prime * result + ((mask == null) ? 0 : mask.hashCode());
        return result;
    }

}
