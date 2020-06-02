// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_class.java
// Do not modify

package org.projectfloodlight.openflow.protocol.ver14;

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

class OFOxmIpDscpMaskedVer14 implements OFOxmIpDscpMasked {
    private static final Logger logger = LoggerFactory.getLogger(OFOxmIpDscpMaskedVer14.class);
    // version: 1.4
    final static byte WIRE_VERSION = 5;
    final static int LENGTH = 6;

        private final static IpDscp DEFAULT_VALUE = IpDscp.NONE;
        private final static IpDscp DEFAULT_VALUE_MASK = IpDscp.NONE;

    // OF message fields
    private final IpDscp value;
    private final IpDscp mask;
//
    // Immutable default instance
    final static OFOxmIpDscpMaskedVer14 DEFAULT = new OFOxmIpDscpMaskedVer14(
        DEFAULT_VALUE, DEFAULT_VALUE_MASK
    );

    // package private constructor - used by readers, builders, and factory
    OFOxmIpDscpMaskedVer14(IpDscp value, IpDscp mask) {
        if(value == null) {
            throw new NullPointerException("OFOxmIpDscpMaskedVer14: property value cannot be null");
        }
        if(mask == null) {
            throw new NullPointerException("OFOxmIpDscpMaskedVer14: property mask cannot be null");
        }
        this.value = value;
        this.mask = mask;
    }

    // Accessors for OF message fields
    @Override
    public IpDscp getMask() {
        return mask;
    }

    @Override
    public long getTypeLen() {
        return 0x80001102L;
    }

    @Override
    public IpDscp getValue() {
        return value;
    }

    public OFOxm<IpDscp> getCanonical() {
        if (IpDscp.NO_MASK.equals(mask)) {
            return new OFOxmIpDscpVer14(value);
        } else if(IpDscp.FULL_MASK.equals(mask)) {
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
    public MatchField<IpDscp> getMatchField() {
        return MatchField.IP_DSCP;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_14;
    }



    public OFOxmIpDscpMasked.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFOxmIpDscpMasked.Builder {
        final OFOxmIpDscpMaskedVer14 parentMessage;

        // OF message fields
        private boolean valueSet;
        private IpDscp value;
        private boolean maskSet;
        private IpDscp mask;

        BuilderWithParent(OFOxmIpDscpMaskedVer14 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public IpDscp getMask() {
        return mask;
    }

    @Override
    public OFOxmIpDscpMasked.Builder setMask(IpDscp mask) {
        this.mask = mask;
        this.maskSet = true;
        return this;
    }
    @Override
    public long getTypeLen() {
        return 0x80001102L;
    }

    @Override
    public IpDscp getValue() {
        return value;
    }

    @Override
    public OFOxmIpDscpMasked.Builder setValue(IpDscp value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public OFOxm<IpDscp> getCanonical()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property canonical not supported in version 1.4");
    }

    @Override
    public boolean isMasked() {
        return true;
    }

    @Override
    public MatchField<IpDscp> getMatchField() {
        return MatchField.IP_DSCP;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_14;
    }



        @Override
        public OFOxmIpDscpMasked build() {
                IpDscp value = this.valueSet ? this.value : parentMessage.value;
                if(value == null)
                    throw new NullPointerException("Property value must not be null");
                IpDscp mask = this.maskSet ? this.mask : parentMessage.mask;
                if(mask == null)
                    throw new NullPointerException("Property mask must not be null");

                //
                return new OFOxmIpDscpMaskedVer14(
                    value,
                    mask
                );
        }

    }

    static class Builder implements OFOxmIpDscpMasked.Builder {
        // OF message fields
        private boolean valueSet;
        private IpDscp value;
        private boolean maskSet;
        private IpDscp mask;

    @Override
    public IpDscp getMask() {
        return mask;
    }

    @Override
    public OFOxmIpDscpMasked.Builder setMask(IpDscp mask) {
        this.mask = mask;
        this.maskSet = true;
        return this;
    }
    @Override
    public long getTypeLen() {
        return 0x80001102L;
    }

    @Override
    public IpDscp getValue() {
        return value;
    }

    @Override
    public OFOxmIpDscpMasked.Builder setValue(IpDscp value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public OFOxm<IpDscp> getCanonical()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property canonical not supported in version 1.4");
    }

    @Override
    public boolean isMasked() {
        return true;
    }

    @Override
    public MatchField<IpDscp> getMatchField() {
        return MatchField.IP_DSCP;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_14;
    }

//
        @Override
        public OFOxmIpDscpMasked build() {
            IpDscp value = this.valueSet ? this.value : DEFAULT_VALUE;
            if(value == null)
                throw new NullPointerException("Property value must not be null");
            IpDscp mask = this.maskSet ? this.mask : DEFAULT_VALUE_MASK;
            if(mask == null)
                throw new NullPointerException("Property mask must not be null");


            return new OFOxmIpDscpMaskedVer14(
                    value,
                    mask
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFOxmIpDscpMasked> {
        @Override
        public OFOxmIpDscpMasked readFrom(ByteBuf bb) throws OFParseError {
            // fixed value property typeLen == 0x80001102L
            int typeLen = bb.readInt();
            if(typeLen != (int) 0x80001102)
                throw new OFParseError("Wrong typeLen: Expected=0x80001102L(0x80001102L), got="+typeLen);
            IpDscp value = IpDscp.readByte(bb);
            IpDscp mask = IpDscp.readByte(bb);

            OFOxmIpDscpMaskedVer14 oxmIpDscpMaskedVer14 = new OFOxmIpDscpMaskedVer14(
                    value,
                      mask
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", oxmIpDscpMaskedVer14);
            return oxmIpDscpMaskedVer14;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFOxmIpDscpMaskedVer14Funnel FUNNEL = new OFOxmIpDscpMaskedVer14Funnel();
    static class OFOxmIpDscpMaskedVer14Funnel implements Funnel<OFOxmIpDscpMaskedVer14> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFOxmIpDscpMaskedVer14 message, PrimitiveSink sink) {
            // fixed value property typeLen = 0x80001102L
            sink.putInt((int) 0x80001102);
            message.value.putTo(sink);
            message.mask.putTo(sink);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFOxmIpDscpMaskedVer14> {
        @Override
        public void write(ByteBuf bb, OFOxmIpDscpMaskedVer14 message) {
            // fixed value property typeLen = 0x80001102L
            bb.writeInt((int) 0x80001102);
            message.value.writeByte(bb);
            message.mask.writeByte(bb);


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFOxmIpDscpMaskedVer14(");
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
        OFOxmIpDscpMaskedVer14 other = (OFOxmIpDscpMaskedVer14) obj;

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
