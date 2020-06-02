// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_class.java
// Do not modify

package org.projectfloodlight.openflow.protocol.ver15;

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

class OFOxmBsnInnerEthSrcVer15 implements OFOxmBsnInnerEthSrc {
    private static final Logger logger = LoggerFactory.getLogger(OFOxmBsnInnerEthSrcVer15.class);
    // version: 1.5
    final static byte WIRE_VERSION = 6;
    final static int LENGTH = 10;

        private final static MacAddress DEFAULT_VALUE = MacAddress.NONE;

    // OF message fields
    private final MacAddress value;
//
    // Immutable default instance
    final static OFOxmBsnInnerEthSrcVer15 DEFAULT = new OFOxmBsnInnerEthSrcVer15(
        DEFAULT_VALUE
    );

    // package private constructor - used by readers, builders, and factory
    OFOxmBsnInnerEthSrcVer15(MacAddress value) {
        if(value == null) {
            throw new NullPointerException("OFOxmBsnInnerEthSrcVer15: property value cannot be null");
        }
        this.value = value;
    }

    // Accessors for OF message fields
    @Override
    public long getTypeLen() {
        return 0x32e06L;
    }

    @Override
    public MacAddress getValue() {
        return value;
    }

    public OFOxm<MacAddress> getCanonical() {
        // exact match OXM is always canonical
        return this;
    }

    @Override
    public MacAddress getMask()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property mask not supported in version 1.5");
    }

    @Override
    public boolean isMasked() {
        return false;
    }

    @Override
    public MatchField<MacAddress> getMatchField() {
        return MatchField.BSN_INNER_ETH_SRC;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }



    public OFOxmBsnInnerEthSrc.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFOxmBsnInnerEthSrc.Builder {
        final OFOxmBsnInnerEthSrcVer15 parentMessage;

        // OF message fields
        private boolean valueSet;
        private MacAddress value;

        BuilderWithParent(OFOxmBsnInnerEthSrcVer15 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public long getTypeLen() {
        return 0x32e06L;
    }

    @Override
    public MacAddress getValue() {
        return value;
    }

    @Override
    public OFOxmBsnInnerEthSrc.Builder setValue(MacAddress value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public OFOxm<MacAddress> getCanonical()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property canonical not supported in version 1.5");
    }

    @Override
    public MacAddress getMask()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property mask not supported in version 1.5");
    }

    @Override
    public boolean isMasked() {
        return false;
    }

    @Override
    public MatchField<MacAddress> getMatchField() {
        return MatchField.BSN_INNER_ETH_SRC;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }



        @Override
        public OFOxmBsnInnerEthSrc build() {
                MacAddress value = this.valueSet ? this.value : parentMessage.value;
                if(value == null)
                    throw new NullPointerException("Property value must not be null");

                //
                return new OFOxmBsnInnerEthSrcVer15(
                    value
                );
        }

    }

    static class Builder implements OFOxmBsnInnerEthSrc.Builder {
        // OF message fields
        private boolean valueSet;
        private MacAddress value;

    @Override
    public long getTypeLen() {
        return 0x32e06L;
    }

    @Override
    public MacAddress getValue() {
        return value;
    }

    @Override
    public OFOxmBsnInnerEthSrc.Builder setValue(MacAddress value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public OFOxm<MacAddress> getCanonical()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property canonical not supported in version 1.5");
    }

    @Override
    public MacAddress getMask()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property mask not supported in version 1.5");
    }

    @Override
    public boolean isMasked() {
        return false;
    }

    @Override
    public MatchField<MacAddress> getMatchField() {
        return MatchField.BSN_INNER_ETH_SRC;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }

//
        @Override
        public OFOxmBsnInnerEthSrc build() {
            MacAddress value = this.valueSet ? this.value : DEFAULT_VALUE;
            if(value == null)
                throw new NullPointerException("Property value must not be null");


            return new OFOxmBsnInnerEthSrcVer15(
                    value
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFOxmBsnInnerEthSrc> {
        @Override
        public OFOxmBsnInnerEthSrc readFrom(ByteBuf bb) throws OFParseError {
            // fixed value property typeLen == 0x32e06L
            int typeLen = bb.readInt();
            if(typeLen != 0x32e06)
                throw new OFParseError("Wrong typeLen: Expected=0x32e06L(0x32e06L), got="+typeLen);
            MacAddress value = MacAddress.read6Bytes(bb);

            OFOxmBsnInnerEthSrcVer15 oxmBsnInnerEthSrcVer15 = new OFOxmBsnInnerEthSrcVer15(
                    value
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", oxmBsnInnerEthSrcVer15);
            return oxmBsnInnerEthSrcVer15;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFOxmBsnInnerEthSrcVer15Funnel FUNNEL = new OFOxmBsnInnerEthSrcVer15Funnel();
    static class OFOxmBsnInnerEthSrcVer15Funnel implements Funnel<OFOxmBsnInnerEthSrcVer15> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFOxmBsnInnerEthSrcVer15 message, PrimitiveSink sink) {
            // fixed value property typeLen = 0x32e06L
            sink.putInt(0x32e06);
            message.value.putTo(sink);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFOxmBsnInnerEthSrcVer15> {
        @Override
        public void write(ByteBuf bb, OFOxmBsnInnerEthSrcVer15 message) {
            // fixed value property typeLen = 0x32e06L
            bb.writeInt(0x32e06);
            message.value.write6Bytes(bb);


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFOxmBsnInnerEthSrcVer15(");
        b.append("value=").append(value);
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
        OFOxmBsnInnerEthSrcVer15 other = (OFOxmBsnInnerEthSrcVer15) obj;

        if (value == null) {
            if (other.value != null)
                return false;
        } else if (!value.equals(other.value))
            return false;
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;

        result = prime * result + ((value == null) ? 0 : value.hashCode());
        return result;
    }

}
